#include"ros/ros.h"
#include"learning_head/hello.h"

namespace hello_ns{

void MyHello::run(){
    ROS_INFO("run is resdy !");
}
}

int main(int argc,char** argv){
    ros::init(argc,argv,"hello_head");
    hello_ns::MyHello myhello;
    myhello.run();

    return 0;
}