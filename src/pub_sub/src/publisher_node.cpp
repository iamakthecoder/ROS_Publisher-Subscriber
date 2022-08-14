#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "publisher");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("msg_topic",1);
    ros::Rate loopRate(10);

    int count=0;
    while(ros::ok()){
        std_msgs::String message;
        message.data = "This is a dummy string "+std::to_string(count);
        ROS_INFO_STREAM(message.data);
        pub.publish(message);
        ros::spinOnce();
        loopRate.sleep();
        count++;
    }

    return 0;
}