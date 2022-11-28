#include"ros/ros.h"
#include"std_msgs/String.h"
#include<sstream>
/*
    话题通信
    发布者
*/

int main(int argc,char** argv){
    ros::init(argc,argv,"publisher");
    ros::NodeHandle n;
    ros::Publisher pub_string=n.advertise<std_msgs::String>("string",10);
    std_msgs::String msg;
    ros::Rate rate(10);
    int count=0;
    ros::Duration(3).sleep();//发布后先休眠（用于在master中注册）
    while(ros::ok()){
        count++;
        //msg.data="hello";
        std::stringstream ss;
        ss<<"hello -->"<<count;
        msg.data=ss.str();
        pub_string.publish(msg);
        ROS_INFO("publisher: %s",ss.str().c_str());
        rate.sleep();
        ros::spinOnce();//处理回调函数（若有）
    }
    



    return 0;
}