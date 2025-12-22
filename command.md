0. Kết nối ssh (pi và laptop cần kết nối cùng mạng với nhau)

Thông tin pi:

		Username: pi-robot
		
		password: 88888888
		
Cấu hình ros2 để dùng mạng trên cả pi và laptop, set biến môi trường trên cả pi và laptop:

		sudo gedit ~/.bashrc
	
- thêm vào file:

		export ROS_DOMAIN_ID=0
		
		export ROS_LOCALHOST_ONLY=0
		
- Kiểm tra kết nối:

  +, pub: 
  
   		ros2 topic pub /test_topic std_msgs/String "data: 'Hello from Pi'" -r 1
  
  +, sub:
   
   		ros2 topic echo /test_topic
		
Kết nối ssh:

		ssh <username>@<IP_pi>

1. Trên Laptop

		git clone https://github.com/nguyendatxtnd/Mobile_robot_lane_following-.git
	
		cd /Mobile_robot_lane_following/workspace 
	
		colcon build
	
		source install/setup.bash
	
		ros2 launch file_launch calculation_n.py
	
	
2. Trên pi

LƯU Ý: TRƯỚC KHI RÚT NGUỒN CỦA PI, CẦN TẮT PI BẰNG LỆNH SAU:

		sudo poweroff 

   Chuyển đến ws: 
	
		cd ~/DA_RB_TTNT/workspace
	
   Mở terminal ảo để chạy:
   
		tmux
		
   - Chia cửa sổ (chia ngang):
  
  			(Ctrl + B) + (Shift + ")
  
   - Chia cửa sổ (chia dọc):
   		
   			(Ctrl + B) + (Shift + 5)
   
   - Chuyển đổi trỏ giữa các của số:
   	
   			(Ctrl + B) + (các phím mũi tên theo hướng mong muốn)
   	
   - Thay đổi kích thước của sổ:
   
   			giữ (Ctrl + B) + (phím các mũi tên)
   			
   - Thoát cửa sổ:
   
   			exit 
   		
   Cửa sổ 1 (lấy dữ liệu picam):
   
   		source install/setup.bash
   
   		ros2 run robot_brigde read_send_image.py
   
   Cửa sổ 2 (gửi tín hiệu đến động cơ):
   
   		source install/setup.bash
   
   		ros2 run robot_brigde motor_control.py
   		
   
   	
   
  
   
  		
  
  			
  
  
  		
	

