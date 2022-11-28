#include"ros/ros.h"

int main(int argc,char** argv){
    setlocale(LC_ALL,"");//解决中文乱码

    ros::init(argc,argv,"hello_c");
    ROS_INFO("hello你好");

    return 0;
}