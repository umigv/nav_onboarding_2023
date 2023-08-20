#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>


/*
This ros package is not meant to be viewed by new members.
If your a new member and have not completed the tutorial turn around now.
Viewing this code will ruin all the fun!

------------SECRET MESSAGE BELOW DON"T CHEAT----------------------------


------------SECRET MESSAGE BELOW DON"T CHEAT----------------------------


------------SECRET MESSAGE BELOW DON"T CHEAT----------------------------


------------SECRET MESSAGE BELOW DON"T CHEAT----------------------------


------------SECRET MESSAGE BELOW DON"T CHEAT----------------------------


------------SECRET MESSAGE BELOW DON"T CHEAT----------------------------


------------SECRET MESSAGE BELOW DON"T CHEAT----------------------------


------------SECRET MESSAGE BELOW DON"T CHEAT----------------------------


------------SECRET MESSAGE BELOW DON"T CHEAT----------------------------


------------SECRET MESSAGE BELOW DON"T CHEAT----------------------------
  */

int main(int argc, char **argv){
    ros::init(argc, argv, "secret_msg");
    ros::NodeHandle sec_msg;
    std_msgs::String secret;
    secret.data =  "WOW!! You found the secret message.'\n'"
                "To get the code press 2-777-888 into your phone. Hint: look at the letters.'\n'" 
                "Send the code to the vault keypad to get your reward."; 
    //ROS_INFO_STREAM(secret.data);
    ros::Publisher secret_msg_pub = sec_msg.advertise<std_msgs::String>("secret_msg", 1000);
    ros::Rate loop_rate(10);
    while(ros::ok()){
        secret_msg_pub.publish(secret);
        ros::spinOnce();
        loop_rate.sleep();
    }
}
