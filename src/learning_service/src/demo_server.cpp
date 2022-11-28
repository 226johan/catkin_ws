#include"ros/ros.h"
#include"learning_service/AddInts.h"

bool Callback(learning_service::AddInts::Request &request,learning_service::AddInts::Response &response){
    //处理请求
    int num1=request.num1;
    int num2=request.num2;
    ROS_INFO("request: num1:%d,num2:%d",num1,num2);

    //组织相应
    int sum=num1+num2;
    response.sum=sum;
    ROS_INFO("respone: sum:%d",sum);

    return true;
}


int main(int argc,char** argv){
    ros::init(argc,argv,"service");
    ros::NodeHandle n;
    ros::ServiceServer server=n.advertiseService("addInts",Callback);
    ROS_INFO("server is start");

    ros::spin();

    return 0;
}