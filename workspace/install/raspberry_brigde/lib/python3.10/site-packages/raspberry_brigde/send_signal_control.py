import rclpy
from rclpy.node import Node
from rclpy.logging import get_logger
from type_msg.msg import OffsetAngle
from type_msg.msg import SignalControl
from std_msgs.msg import Bool
import matplotlib.pyplot as plt
from raspberry_brigde.PID import PID
import os
import datetime
import math

Kp_offset = 5.0
Ki_offset = 0.0
Kd_offset = 0.01

K = 1.0745 #ti so giua van toc mong muon va van toc thuc te 
#K = 0.8
L = 0.165  #khoang cach giua 2 banh (m)
v_target = 0.035 # van toc dai (m/s) 
R = 0.0342  # ban kinh banh xe
#gear_ratio = 48

#V_DC_MAX = 130 #v/ph

class PubSignalControl(Node):
    def __init__(self):
        super().__init__("pub_signal_control")
        self.sub_offset_lane = self.create_subscription(OffsetAngle,
                                            'lane_offset',
                                            self.lane_offset_callback,
                                            10)
        self.sub_offset_obstacle= self.create_subscription(OffsetAngle,
                                            'obstacle_offset',
                                            self.obstacle_offset_callback,
                                            10)
        self.sub_obstacle= self.create_subscription(Bool,
                                            'obstacle',
                                            self.obstacle_callback,
                                            10)
        self.pub = self.create_publisher(SignalControl,
                                         'signal_control',
                                         10)
        
        self.lane_offset = 0.0
        self.obstacle_offset = 0.0
        self.obstacle_flag = False
        self.prev_obstacle_flag = False
        self.offset = None
        self.mode = "LANE"

        self.pid_offset = PID(Kp=Kp_offset, Ki=Ki_offset, Kd=Kd_offset)
        
        self.offset_history = []
        # self.v_history = []
        # self.omega_history = []
        # self.phi_l_history = []
        # self.phi_r_history = []
        # self.n_l_history = []
        # self.n_r_history = []

        self.timer = self.create_timer(0.2, self.callback)
    
    def lane_offset_callback(self,msg):
        self.lane_offset = msg.offset
    def obstacle_offset_callback(self,msg):
        self.obstacle_offset = msg.offset
    def obstacle_callback(self,msg):
        self.obstacle_flag = msg.data

    def callback(self):
        if self.obstacle_flag != self.prev_obstacle_flag:
            self.pid_offset.reset()
            self.prev_obstacle_flag = self.obstacle_flag
            if self.obstacle_flag == True:
                self.mode =  "OBSTACLE"
            else:
                self.mode =  "LANE"
            self.get_logger().info(f"Switched to mode: {self.mode}")

        if self.mode == "OBSTACLE":
            self.offset = self.obstacle_offset 
        else:
            self.offset = self.lane_offset
            
        omega = self.pid_offset.update(self.offset)
        #v =  K * v_target * math.exp(-1 * abs(self.offset))
        v =  K * v_target 

        v_left = v - omega * L/2
        v_right = v + omega * L/2

        phi_left = v_left/R
        phi_right = v_right/R 
        
        n_left = phi_left * (60/(2*math.pi))
        n_right = phi_right * (60/(2*math.pi))

        self.get_logger().info(f"mode: {self.mode}, v: {v:.2f}, omega: {omega:.2f} -- n_left: {n_left:.2f}, n_right: {n_right:.2f}")

        msg_send_pi = SignalControl()
        msg_send_pi.n_l = n_right
        msg_send_pi.n_r = n_left
        self.pub.publish(msg_send_pi)

        self.offset_history.append(self.offset)
        # self.v_history.append(v)
        # self.omega_history.append(omega)
        # self.n_l_history.append(n_left)
        # self.n_r_history.append(n_right)

    def plot_history(self):
        save_path="plot"
        os.makedirs(save_path, exist_ok=True)

        # plt.figure(figsize=(12, 8))
        plt.figure(figsize=(10, 5))

        plt.plot(self.offset_history, label="Offset (m)")
        plt.ylabel("Offset (m)")
        plt.xlabel("Step")
        plt.title("Offset History")
        plt.legend()
        plt.grid(True)

        # plt.subplot(3,1,1)
        # plt.plot(self.offset_history, label="Offset (m)")
        # plt.ylabel("Offset")
        # plt.legend()
        # plt.grid(True)

        # plt.subplot(3,1,2)
        # plt.plot(self.v_history, label="Linear Velocity v (m/s)")
        # plt.plot(self.omega_history, label="Angular Velocity ω (rad/s)")
        # plt.ylabel("v / ω")
        # plt.legend()
        # plt.grid(True)

        # plt.subplot(3,1,3)
        # plt.plot(self.phi_l_history, label="phi_left (rad/s)")
        # plt.plot(self.phi_r_history, label="phi_right (rad/s)")
        # plt.ylabel("Wheel Velocity")
        # plt.xlabel("Step")
        # plt.legend()
        # plt.grid(True)

        plt.tight_layout()
        timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = os.path.join(save_path, f"pid_plot_{timestamp}.png")
        plt.savefig(filename)
        plt.close()  

        self.get_logger().info(f"plot save in: {filename}")

def main(args=None):
    rclpy.init(args=args)
    node_sg= PubSignalControl()
    logger = get_logger("main_logger")
    try:
        logger.info("pub signal control started ...")
        rclpy.spin(node_sg)
    except KeyboardInterrupt:
        logger.info("pub signal control stoped!")
    finally:
        node_sg.plot_history()
        node_sg.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == "__main__":
    main() 

