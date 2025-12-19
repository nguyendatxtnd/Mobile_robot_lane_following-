from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    node1 = Node(
        package="lane_following",
        executable="lane_detection",
        name="lane_detection",
        output="screen",
        emulate_tty=True,
        prefix="xterm -hold -bg black -fg white -e"
    )

    node2 = Node(
        package="obstacle_detection",
        executable="obstacle_detection",
        name="obstacle_detection",
        output="screen",
        emulate_tty=True,
        prefix="xterm -hold -bg black -fg white -e"
    )

    node3 = Node(
        package="raspberry_brigde",
        executable="send_signal_control",
        name="send_signal_control",
        output="screen",
        emulate_tty=True,
        prefix="xterm -hold -bg black -fg white -e"
    )

    ld = LaunchDescription()
    ld.add_action(node1)
    ld.add_action(node2)
    ld.add_action(node3)
    return ld

