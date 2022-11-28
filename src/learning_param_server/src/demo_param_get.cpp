#include"ros/ros.h"
/*
    参数查询
    实现:
        ros::NodeHandle
            param(key,default_value)
            存在返回结果，否则返回default_value

        getParam(key,value)
            存在，返回true 且将值赋给value
            若不存在，返回值为false 且不为参数2赋值

        getParamCached(key,value) 提高变量获取效率（从缓存中获取数据）
            存在，返回true 且将返回值赋给Value
            若不存在，返回值为false 且不为参数2赋值
*/


int main(int argc,char** argv){
    ros::init(argc,argv,"param_get");
    ros::NodeHandle n;
    //--------------ros::NodeHandle
    //1.param
    double radius=n.param("radius",0.5);
    ROS_INFO("radius = %.2f",radius);

    //2.getParam
    double radius2=0.0;
    bool result=n.getParam("radius",radius2);
    
    //3.getParamCached 
    //bool result=n.getParamCached("radius",radius2);
    if(result){
        ROS_INFO("radius = %.2f",radius2);
    }
    else{
        ROS_INFO("param error !");
    }
    return 0;
}