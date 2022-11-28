#include"ros/ros.h"

/*
    需要实现参数的新增与修改
    需求：
        首先设置机器人的共享参数，类型、半径（0.15m）
        再修改半径（0.2m）
    实现：
        ros::NodeHandle
            setParam("key",value)
        ros::param
            set("key",value)
    修改只需要继续调用 setParam 或 set 函数 保证键是已经存在的，值将会覆盖

    在终端查看参数
    rosparam list   查看参数列表
    rosparam get ${key}   获取参数值
*/


int main(int argc,char** argv)
{
    ros::init(argc,argv,"param_set");
    ros::NodeHandle n;
    //----------------参数增加------------------
    //方案1：n
    n.setParam("type","robot1");
    n.setParam("radius",0.15);
    //方案2：ros::param
    ros::param::set("type_param","robot2");
    ros::param::set("radius_param",0.15);

    //----------------参数修改------------------
    //方案1：n
    n.setParam("radius",0.2);
    //方案2：ros::param
    ros::param::set("radius",0.2);

    return 0;
}