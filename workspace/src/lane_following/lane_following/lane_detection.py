import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
import cv2
from cv_bridge import CvBridge
import numpy as np
from type_msg.msg import OffsetAngle 
import os

import torch
from torchvision import transforms
from FastSCNN.models.FastSCNN import FastSCNN
from ament_index_python.packages import get_package_share_directory

package_share_dir = get_package_share_directory('lane_following')
WEIGHT_PATH = os.path.join(package_share_dir, 'FastSCNN', 'weights', 'fast_scnn_best_weights.pth')

NUM_CLASSES = 2
DEVICE = torch.device("cuda" if torch.cuda.is_available() else "cpu")
DEVICE_NAME = torch.cuda.get_device_name(0) if torch.cuda.is_available() else "CPU"
H_IMAGE = 256
W_IMAGE = 352
#MEAN=[0.6363, 0.6163, 0.6192]
#STD=[0.1996, 0.2243, 0.2501]
#MEAN=[0.52, 0.5111, 0.5059]
#STD=[0.2196, 0.2299, 0.2577]

MEAN=[0.4263, 0.4579, 0.475]
STD=[0.2593, 0.2345, 0.2518]


DISTANCE_LANE = 0.2    #khoang cach 2 lane/ kich thuoc duong di (m)


length = 0.213 # m     29,6, 21,3
width = 0.296   # m
SCALE = 1500 #px/m
BEV_W = int(width * SCALE)
BEV_H = int(length * SCALE)

# Toa do mat phang anh
src_point = np.array([[72, 113],
                       [280, 115],
                       [344, 218],
                       [5, 212]], dtype=np.float32)
                       
# Toa do mat dat (PIXEL BEV)
dst_point = np.array([ [0, 0],
                       [BEV_W, 0],
                       [BEV_W, BEV_H],
                       [0, BEV_H]], dtype=np.float32)
# Ma tran homography
H_MATRIX, _ = cv2.findHomography(src_point, dst_point)

transform = transforms.Compose([
    transforms.ToTensor(),
    transforms.Normalize(mean=MEAN, std=STD)
])


print(f"load model ...")
model = FastSCNN(num_classes=NUM_CLASSES)
model.load_state_dict(torch.load(WEIGHT_PATH, map_location=DEVICE))
model.to(DEVICE)
model.eval()
print(f"DONE!\nUSED DEVICE: {DEVICE_NAME}")

def visualize(frame, mask_pred_, mask_bev_, cx_lane):
    disp_size = (W_IMAGE, H_IMAGE)

    BEV_W = mask_bev_.shape[1]
    BEV_H = mask_bev_.shape[0]

    if mask_pred_.shape != frame.shape[:2]:
        mask_pred_ = cv2.resize(mask_pred_, (frame.shape[1], frame.shape[0]), interpolation=cv2.INTER_NEAREST)
    if mask_bev_.shape != frame.shape[:2]:
        mask_bev_ = cv2.resize(mask_bev_, (frame.shape[1], frame.shape[0]), interpolation=cv2.INTER_NEAREST)    
    
    mask_color = np.zeros_like(frame)
    mask_color[mask_pred_ == 1] = [0, 255, 0]  
    overlay = cv2.addWeighted(frame, 0.8, mask_color, 0.5, 0) 

    mask_color_bev = np.zeros_like(frame)
    mask_color_bev[mask_bev_ == 1] = [0, 255, 0] 

    roi_ymin = 0.85
    roi_ymax = 0.95

    h, w = mask_pred_.shape
    y_min = int(h * roi_ymin)
    y_max = int(h * roi_ymax)

    scale_x = disp_size[0] / w
    scale_y = disp_size[1] / h

    y_min_disp = int(y_min * scale_y)
    y_max_disp = int(y_max * scale_y)

    cv2.rectangle(
        mask_color_bev,
        (0,      y_min_disp),
        (disp_size[0], y_max_disp),
        (0, 255, 255), 2
    )


    if cx_lane != 0.0: 
        center_x_bev = BEV_W // 2
        center_y_bev = int(BEV_H * 0.9)

        scale_x = disp_size[0] / BEV_W
        scale_y = disp_size[1] / BEV_H

        center_x_disp = int(center_x_bev * scale_x)
        center_y_disp = int(center_y_bev * scale_y)
        cv2.circle(mask_color_bev, (center_x_disp, center_y_disp), 5, (255, 0, 0), -1) 

        lane_x_disp = int(cx_lane * scale_x)
        cv2.circle(mask_color_bev, (lane_x_disp, center_y_disp), 5, (0, 0, 255), -1) 
    
    a1 = cv2.resize(frame, disp_size)
    a2 = cv2.resize(overlay, disp_size)  
    a3 = cv2.resize(mask_color, disp_size)
    
    sep_h = np.ones((disp_size[1], 5, 3), dtype=np.uint8) * 255   
    sep_v = np.ones((5, disp_size[0]*2 + 5*1, 3), dtype=np.uint8) * 255

    top_row = np.hstack((a1, sep_h, a2))
    bottom_row = np.hstack((a3, sep_h, mask_color_bev))
    combined = np.vstack((top_row, sep_v, bottom_row))

    cv2.imshow("Lane Detection Visualization", combined)
    cv2.waitKey(1)

class LaneDetection(Node):
    def __init__ (self):
        super().__init__("lane_detection")
        self.sub = self.create_subscription(CompressedImage,
                                            'image_data',
                                            self.callback,
                                            10)
        self.pub = self.create_publisher(OffsetAngle,
                                         'lane_offset',
                                         10)
        self.bridge = CvBridge()
        self.BEV_W = BEV_W
        self.BEV_H = BEV_H
        self.SCALE = SCALE
        self.DISTANCE_LANE = DISTANCE_LANE

        #cv2.namedWindow("Lane Detection Visualization", cv2.WINDOW_NORMAL)
        
        
    def callback(self, msg_image):
        image = self.bridge.compressed_imgmsg_to_cv2(msg_image)
        if image is None:
            self.get_logger().warn("Empty image received!")
            return

        resized = cv2.resize(image, (W_IMAGE, H_IMAGE)) 
        rgb = cv2.cvtColor(resized, cv2.COLOR_BGR2RGB)
        img_tensor = transform(rgb).unsqueeze(0).to(DEVICE) 

        with torch.no_grad():
            output = model(img_tensor)
            if isinstance(output, (tuple, list)):
                output = output[0]
            mask_pred = torch.argmax(output, dim=1).squeeze(0).cpu().numpy().astype(np.uint8)

        mask_bev = cv2.warpPerspective(mask_pred.astype(np.uint8), H_MATRIX, 
                                        (self.BEV_W, self.BEV_H),
                                        flags=cv2.INTER_NEAREST)

        offset, cx_lane = self.CalculateSignalControl(mask_bev)

        if abs(offset) < 0.01:
           offset = 0.0


        self.get_logger().info(f"Offset: {offset} m") 

        visualize(image, mask_pred, mask_bev, cx_lane)
        
        msg = OffsetAngle()
        msg.offset = offset
        msg.angle = 0.0 
        self.pub.publish(msg)
    
    def CalculateSignalControl(self, mask_bev_):
        h, w = mask_bev_.shape
        lane_points = np.argwhere(mask_bev_ == 1)
        
        roi_ymin = 0.85
        roi_ymax = 0.95
        
        y_min = int(h * roi_ymin)
        y_max = int(h * roi_ymax)
        roi_points = lane_points[
            (lane_points[:, 0] >= y_min) & (lane_points[:, 0] <= y_max)
        ]
        
        if len(roi_points) < 10: 
            return 0.0, 0.0

        # --- offset ---
        col_roi = roi_points[:, 1]
        left_lane = col_roi[col_roi < w*0.45]
        right_lane = col_roi[col_roi >= w*0.55]

        # if len(left_lane) > 0 and len(right_lane) > 0:
        #     cx_left = np.mean(left_lane)
        #     cx_right = np.mean(right_lane)
        #     cx_lane = (cx_left + cx_right) / 2.0
        # elif len(left_lane) > 0 and len(right_lane) == 0:
        #     cx_left = np.mean(left_lane)
        #     cx_lane = cx_left + (self.DISTANCE_LANE * self.SCALE / 2.0)

        # elif len(left_lane) == 0 and len(right_lane) > 0:
        #     cx_right = np.mean(right_lane)
        #     cx_lane = cx_right - (self.DISTANCE_LANE * self.SCALE / 2.0)
        # else:
        #     return 0.0, 0.0
        
        if len(left_lane) > 0 and len(right_lane) > 0:
            cx_left = np.mean(left_lane)
            cx_right = np.mean(right_lane)
            cx_lane = ((cx_right - cx_left) / 2.0) + cx_left
        elif len(left_lane) > 0 and len(right_lane) == 0:
            cx_left = np.mean(left_lane)
            cx_lane = w/2 + 0.025*self.SCALE

        elif len(left_lane) == 0 and len(right_lane) > 0:
            cx_right = np.mean(right_lane)
            cx_lane = w/2 - 0.025*self.SCALE
        else:
            return 0.0, 0.0

        offset_px = cx_lane - (w/2)   
        offset_m = offset_px / self.SCALE  

        return -offset_m, cx_lane

    def destroy_node(self):
        cv2.destroyAllWindows()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node_ld = LaneDetection()
    try:
        node_ld.get_logger().info("Start detect lane ... ")
        rclpy.spin(node_ld)
    except KeyboardInterrupt:
        node_ld.get_logger().info("stoped lane detection!")
    finally:
        node_ld.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == "__main__":
    main()

