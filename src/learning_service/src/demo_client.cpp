#include"ros/ros.h"
#include"learning_service/AddInts.h"
/*
    问题：
        如果先启动客户端，那么会请求异常
    需求：
        如果先启动客户端，不要直接抛出异常，而是挂起，等服务器启动后，在正常请求
    解决：
        在ROS中内置了相关函数，这些函数可以让客户端启动后挂起，等待服务器启动
*/


int main(int argc,char** argv){
    //获取命令中的参数
    if(argc != 3){
        ROS_INFO("argc error!");
        return 1;
    }

    ros::init(argc,argv,"client");
    ros::NodeHandle n;
    ros::ServiceClient client=n.serviceClient<learning_service::AddInts>("addInts");

    learning_service::AddInts ai;
    //组织请求
    ai.request.num1=atoi(argv[1]);
    ai.request.num2=atoi(argv[2]);

    //处理响应
    //调用判断服务器状态的函数
    //函数1
    //client.waitForExistence();
    //函数2
    ros::service::waitForService("addInts");
    bool flag=client.call(ai);
    if(flag==true){
        ROS_INFO("response true");
        ROS_INFO("  sum=%d",ai.response.sum);
    }
    else{
        ROS_INFO("response flase");
    }
    return 0;
}