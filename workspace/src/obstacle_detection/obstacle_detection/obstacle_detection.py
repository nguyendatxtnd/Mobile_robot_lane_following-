import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
from type_msg.msg import OffsetAngle
from std_msgs.msg import Bool
from cv_bridge import CvBridge

import torch
from ultralytics import YOLO
import cv2
import time
from ament_index_python.packages import get_package_share_directory
import os

package_share_dir = get_package_share_directory("obstacle_detection")
WEIGHT_PATH = os.path.join(package_share_dir, "YOLO", "vatcan_best.pt")
THRESHOLD = 0.85
THRESHOLD_2 = 0.05
LABEL = ['wheel']

DEVICE = torch.device("cuda" if torch.cuda.is_available() else "cpu")
DEVICE_NAME = torch.cuda.get_device_name(0) if torch.cuda.is_available() else "CPU"

try:
    model = YOLO(WEIGHT_PATH)
    model.to(DEVICE)
    print(f"Model running on: {DEVICE_NAME}")
except Exception as e:
    print(f"Model load error: {e}")
    exit()

class ObstacleDetection(Node):
    def __init__(self):
        super().__init__("obstacle_detection")
        self.sub = self.create_subscription(CompressedImage,
                                            'image_data',
                                            self.callback,
                                            10)
        self.pub_offset_obstacle = self.create_publisher(OffsetAngle,
                                                         'obstacle_offset',
                                                         10)
        self.pub_obstacle = self.create_publisher(Bool,
                                                  'obstacle',
                                                  10)
        
        self.bridge = CvBridge()
        
        self.change_lane = False   # tin hieu chuyen lan khi phat hien vat can
        self.prev_change_lane = False # tin hieu chuyen lan o frame truoc
        self.position = 0  # 0: l, 1: r
        self.obstacle_offset = 0.0
        self.timeout_duration = 3.0 # timeout
        self.last_obstacle_time = 0.0  #thoi diem phat hien vat can

        cv2.namedWindow("Obstacle Detection", cv2.WINDOW_NORMAL)

    def callback(self, msg):
        image = self.bridge.compressed_imgmsg_to_cv2(msg)
        if image is None:
            self.get_logger().warn("Empty image received!")
            return

        detected, frame_show = self.detection_obstacle(image)
        current_time = time.time()
        
        if detected == True and self.change_lane == False:
            self.last_obstacle_time = current_time

        self.change_lane = detected

        in_timeout = (current_time - self.last_obstacle_time) < self.timeout_duration
        time_ = max(0.0, self.timeout_duration - (current_time - self.last_obstacle_time))

        if self.change_lane == True:
            if self.position == 0:
                self.obstacle_offset = -0.033
            else:
                self.obstacle_offset = +0.033
        elif self.change_lane == False and in_timeout == True:
            self.change_lane = True
            if self.position == 0:
                self.obstacle_offset = -0.035
            else:
                self.obstacle_offset = +0.035
        else:
            if self.prev_change_lane == True:
                self.position = 1 - self.position
            self.obstacle_offset = 0.0

        self.prev_change_lane = self.change_lane
        

        self.get_logger().info(f"Offset: {self.obstacle_offset:.2f} m")

        msg_offset = OffsetAngle()
        msg_offset.offset = self.obstacle_offset
        msg_offset.angle = 0.0

        msg_flag = Bool()
        msg_flag.data = self.change_lane

        self.pub_offset_obstacle.publish(msg_offset)
        self.pub_obstacle.publish(msg_flag) 

        
        status_text1 = f"Change lane: {self.change_lane}"
        status_text2 = f"Lane: {'Right' if self.position else 'Left'}"
        status_text3 = f"Timeout: {time_:.1f}s"
        status_text4 = f"offset: {self.obstacle_offset} m"

        cv2.putText(frame_show, status_text1, (10, 20), cv2.FONT_HERSHEY_SIMPLEX, 
                    0.5, (0, 255, 255), 1)
        cv2.putText(frame_show, status_text2, (10, 40), cv2.FONT_HERSHEY_SIMPLEX, 
                    0.5, (0, 255, 255), 1)
        cv2.putText(frame_show, status_text3, (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 
                    0.5, (0, 255, 255), 1)
        cv2.putText(frame_show, status_text4, (10, 80), cv2.FONT_HERSHEY_SIMPLEX, 
                    0.5, (0, 255, 255), 1)

        cv2.imshow("Obstacle Detection", frame_show)
        cv2.waitKey(1)



    def detection_obstacle(self, image_):
        flag_obstacle = False
        h, w = image_.shape[:2]
        frame_area = h * w

        results = model(image_, conf=THRESHOLD, verbose=False, device=DEVICE)
        frame_plot = results[0].plot()  
        for box in results[0].boxes:
            label_obs = model.names[int(box.cls.item())]
            if label_obs in LABEL:
                x1, y1, x2, y2 = map(int, box.xyxy[0].tolist())
                obstacle_area = (x2 - x1) * (y2 - y1)
                area_ratio = obstacle_area / frame_area
                if area_ratio >= THRESHOLD_2:
                    flag_obstacle = True
                    break

        return flag_obstacle, frame_plot

    def destroy_node(self):
        cv2.destroyAllWindows()
        super().destroy_node()
        self.get_logger().info("Stop obstacle detection!")

def main(args=None):
    rclpy.init(args=args)
    node = ObstacleDetection()
    try:
        node.get_logger().info("Start obstacle detection ...")
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Stop obstacle detection!")
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == "__main__":
    main()

