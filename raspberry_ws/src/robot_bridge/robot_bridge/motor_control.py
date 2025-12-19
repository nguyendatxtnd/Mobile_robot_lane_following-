import rclpy
from rclpy.node import Node
from type_msg.msg import SignalControl
import serial
import time 

class SendUART(Node):
    def __init__(self):
        super().__init__('node_uart')
        self.serial_port = None

        try:
            self.serial_port = serial.Serial(
                port='/dev/serial0',  
                baudrate=115200,
                timeout=1
            )
            time.sleep(2)  
            self.get_logger().info("UART opened ...")
        except serial.SerialException as e:
            self.get_logger().error(f"Cannot open UART: {e}")
            raise e
        
        self.sub = self.create_subscription(SignalControl,
                                            'signal_control',
                                            self.callback,
                                            10)

    def callback(self, msg):
        if not self.serial_port.is_open:
            self.get_logger().error("UART port is not open. Cannot send data.")
            return
        n_right = msg.n_r
        n_left = msg.n_l 
        data_str = f"{n_left},{n_right}\n"
        try:
            self.serial_port.write(data_str.encode('utf-8'))
            self.get_logger().info(f"Sent to STM32: {data_str.strip()}")
        except Exception as e:
            self.get_logger().error(f"UART send error: {e}")
    
    def destroy_node(self):
        if self.serial_port and self.serial_port.is_open:
            self.serial_port.close()
        super().destroy_node()
        
def main(args=None):
    rclpy.init(args=args)
    node = SendUART()
    try:
        node.get_logger().info("started control motor ...")
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("UART node stopped!")
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
       
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

