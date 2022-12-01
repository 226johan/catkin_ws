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

    //4.n.getParamNames
    std::vector<std::string> names;
    n.getParamNames(names);
    for(auto &&name : names){
        ROS_INFO("param_loop: %s",name.c_str());
    }

    //5.n.hasParam
    bool flag = n.hasParam("radius");
    if(flag){
        ROS_INFO("radius haved");
    }
    else{
        ROS_INFO("radius id not have !");
    }

    //6.n.searchParam
    std::string param;
    bool ret = n.searchParam("radius",param);
    if(ret){
        ROS_INFO("search ture ! result is:%s",param.c_str());
    }
    else{
        ROS_INFO("search flase ! result is:%s",param.c_str());
    }

    return 0;
}