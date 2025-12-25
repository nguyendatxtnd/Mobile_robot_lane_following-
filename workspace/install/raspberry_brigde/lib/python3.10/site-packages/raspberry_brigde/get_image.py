import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
from cv_bridge import CvBridge
#import cv2


class GetImage(Node):
    def __init__(self):
        super().__init__("get_image")
        self.subImage = self.create_subscription(CompressedImage,
                                                'image_picam',
                                                self.callback,
                                                10)
        
        self.pubImage = self.create_publisher(CompressedImage,
                                              'image_data',
                                              10)

        self.bridge = CvBridge()
        # self.frame_count = 0

    def callback(self, msg_image):
        image = self.bridge.compressed_imgmsg_to_cv2(msg_image)
        #cv2.imshow("picam view", image)
        #cv2.waitKey(1)

        msgImage = self.bridge.cv2_to_compressed_imgmsg(image, dst_format='jpeg')
        msgImage.header = msg_image.header
        self.pubImage.publish(msgImage)

        # self.frame_count += 1
        # if self.frame_count % 10 == 0:        
        #     self.get_logger().info("get and sub 10 image done")

    def destroy_node(self):
        #cv2.destroyAllWindows()
        super().destroy_node()
        self.get_logger().info("Stopped get image!")

def main(args=None):
    rclpy.init(args=args)
    node = GetImage()
    try:
        node.get_logger().info("Start get image ...")
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("stoped get image!")
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == "__main__":
    main()

