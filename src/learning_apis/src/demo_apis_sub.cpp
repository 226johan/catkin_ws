#include"ros/ros.h"
#include"std_msgs/String.h"
/*
    话题通信
    订阅者

*/
void Callback(const std_msgs::String::ConstPtr &msg){

    ROS_INFO("subscriber: %s",msg->data.c_str());

}

int main(int argc,char** argv){
    ros::init(argc,argv,"subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub_string=n.subscribe("string",10,Callback);
    ros::spin();
    ROS_INFO("spin over !");
    return 0;
}