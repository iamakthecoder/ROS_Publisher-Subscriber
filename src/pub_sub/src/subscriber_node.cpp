#include <ros/ros.h>
#include <std_msgs/String.h>

void call_back(const std_msgs::String& message){
    ROS_INFO("Received: [%s]",message.data.c_str());
}

int main(int argc, char* argv[]){
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("msg_topic",10,call_back);
    ros::spin();
    
    return 0;
}