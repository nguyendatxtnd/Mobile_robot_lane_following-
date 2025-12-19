import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
from cv_bridge import CvBridge
import cv2
import os

class ReadSendImage(Node):
    def __init__(self):
        super().__init__("read_send_image")
        self.pub = self.create_publisher(CompressedImage, "image_picam", 10)
        self.bridge = CvBridge()

        if not os.path.exists("/dev/video0"):
            self.get_logger().error("Not find /dev/video0 – check PiCam!")
            raise RuntimeError("Camera not found")

        self.cap = cv2.VideoCapture(0)
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 352)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 256)
        self.cap.set(cv2.CAP_PROP_FPS, 10)

        if not self.cap.isOpened():
            self.get_logger().error("don't open picam")
            raise RuntimeError("picam not opened")
            
        self.timer = self.create_timer(1/10, self.timer_callback)
        #self.frame_count = 0
        self.get_logger().info("picam open successfully!")

    def timer_callback(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().warning("image unreadabel")
            return

        msg = self.bridge.cv2_to_compressed_imgmsg(frame, dst_format='jpeg')
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "picam_frame"

        self.pub.publish(msg)
        #self.frame_count += 1

        #if self.frame_count % 20 == 0:
        #    self.get_logger().info("Send 10 image done")

    def destroy_node(self):
        if self.cap.isOpened():
            self.cap.release()
        super().destroy_node()
        self.get_logger().info("read and send stopped, camera released!")

def main(args=None):
    rclpy.init(args=args)
    node = ReadSendImage()
    try:
        node.get_logger().info("Start send image ...")
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Node interrupted by user!")
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == '__main__':
    main()

         

