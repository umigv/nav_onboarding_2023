# nav_onboarding_2023
This is the official repository for UMARV Navigation subteams onboarding documents for 2023.

**PREREQUISITES TO STARTING**\
Follow this guide to download docker https://docs.google.com/document/d/1BoBzBi_zj4UksIr_JSo8NRH-JYdkBk_sFzb5_qUIuQs/edit?usp=drive_link

**HOW TO COMPLETE THE NAV ONBOARDING** \
Download docker image \
Open docker using VNC viewer\
Open terminal\
mkdir ~/ros_tutorial_ws/src\
clone this repository\
cd ..\
catkin build\
source devel/setup.bash\
roslaunch secret_msg secret_msg.launch\
Open a new terminal.\
cd ~/ros_tutorial_ws\
source devel/setup.bash\
catkin create pkg <package_name> roscpp rospy std_msgs std_srvs message_generation\
Hint: use -> rosnode list and rosnode info <node_name> to find what topic to subscribe to.\
http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29 \
Go to the link above for a ros publisher, and subscriber tutorial.\
Hint: use -> rosservice list\
http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28c%2B%2B%29 \
Go to the link above for a ros service and client tutorial. \
Call the service you found using rosservice list.\
If you are struggling you can send “HELP” to the service and it will return a helpful message.\
