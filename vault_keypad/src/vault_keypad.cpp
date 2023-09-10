#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <std_srvs/SetBool.h>
#include <vault_keypad/secret.h>
#include <string>

/*
This ros package is not meant to be viewed by new members.
If you are a new member and have not completed the tutorial turn around now.
Viewing this code will ruin all the fun!

------------SECRET REWARD BELOW DON"T CHEAT----------------------------


------------SECRET REWARD BELOW DON"T CHEAT----------------------------


------------SECRET REWARD BELOW DON"T CHEAT----------------------------


------------SECRET REWARD BELOW DON"T CHEAT----------------------------


------------SECRET REWARD BELOW DON"T CHEAT----------------------------


------------SECRET REWARD BELOW DON"T CHEAT----------------------------


------------SECRET REWARD BELOW DON"T CHEAT----------------------------


------------SECRET REWARD BELOW DON"T CHEAT----------------------------


------------SECRET REWARD BELOW DON"T CHEAT----------------------------


------------SECRET REWARD BELOW DON"T CHEAT----------------------------
  */

  bool vualt_keypad_callback(vault_keypad::secret::Request &req, vault_keypad::secret::Response &res){
        if(req.data == "arv" || req.data == "ARV"){
            std_msgs::String reward;
            reward.data = "CONGRATS you're officially a theif, you have stolen: $1";
            for(int i = 0; i < 100; i++){
                reward.data += "000,";
            }
            res.data = reward.data;
            return true;
        } else if(req.data == "HELP" || req.data == "'HELP'"){
            res.data = "USE THE NUMBERS GIVEN TO YOU FROM THE SECRET MESSAGE. " 
            "THEN USE THOSE NUMBERS AND TRANSLATE THEM TO LETTERS ON YOUR PHONES KEYPAD. EX: 9 = W, 99 = X, 999 = Y, 9999 = Z.";
            return false;
        } else{
            res.data = "INCORRECT PASSWORD TRY AGAIN!  |  IF YOU NEED A HINT SEND THE STRING 'HELP'";
            return false;
        }
  }
    int main(int argc, char **argv){
    ros::init(argc, argv, "vault_keypad");
    ros::NodeHandle bank;
    ros::ServiceServer bank_service = bank.advertiseService("Vault_Keypad", &vualt_keypad_callback);
    // std_msgs::String reward;
    // reward.data = "CONGRATS you're officially a theif, you have stolen: $1";
    // for(int i = 0; i < 100; i++){
    //     reward.data += "000,";
    // }
    // ROS_INFO_STREAM(reward.data);
    // ros::Publisher bank_pub = bank.advertise<std_msgs::String>("Vault", 1000);
    ros::Rate loop_rate(10);
    while(ros::ok()){
        ros::spinOnce();
        loop_rate.sleep();
    }
}