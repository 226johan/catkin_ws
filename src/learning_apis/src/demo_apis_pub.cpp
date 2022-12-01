#include"ros/ros.h"
#include"std_msgs/String.h"
#include<sstream>

int main(int argc,char** argv){
/*
    函数：void ros::init(int &argc, char **argv, const std::string &name, uint32_t options = 0U)
    作用：ROS初始化函数
    参数：
        1.argc      ----- 封装实参个数（n+1）
        2.argv      ----- 封装参数的数组
        3.name      ----- 为节点命名（唯一性）
        4.options   ----- 节点启动选项
        返回值：void
    使用：
        1.argc与argv的使用
            如果按照ROS中特定格式传入实参，那么ROS可以加以使用，比如用来设定全局参数，给节点重命名
            语法：rosrun ${pkg} ${type} _${paramName}:=${value}
            eg：rosrun learning_apis demo_apis_pub _length:=2
            
        2.options 的使用
            节点名称需要保证唯一，会导致一个问题，同一个节点不能重复启动
            结果：ROS 中当有重名的节点启动时，之前的节点会被关闭
            需求：特定场景下，需要一个节点多次启动且能正常运行
            解决：设置启动项ros::init_options::AnonymousName
                当创建ROS节点时，会在用户自定义的节点名称后缀随机数，从而避免重名问题
*/

    ros::init(argc,argv,"apis_pub",ros::init_options::AnonymousName);
    ros::NodeHandle n;
/*
    函数：inline ros::Publisher ros::NodeHandle::advertise<std_msgs::String>(const std::string &topic, uint32_t queue_size, bool latch = false)
    作用：创建发布者对象

    模板：被发布的消息的类型
    参数：
        1.话题名称
        2.队列长度
        3.latch（可选） 如果设置为true，会保存发布方的最后一条消息，并且
           新的订阅对象连接到发布方是，发布方会将这条消息发送给订阅者
    使用：
        latch 设置为true的作用？
        以静态地图发布为例，
        方案1：可以使用固定频率发布地图数据，但是效率低
        方案2：可以将地图发布对象的latch设置为true，并且发布方之发送一次数据，每当订阅者连接时，
        将地图数据发送给订阅者（只发送一次）这样提高了数据的发送效率
*/
    ros::Publisher pub = n.advertise<std_msgs::String>("string",10,true);
    
    std_msgs::String msg;
    ros::Rate rate(10);
    int count=0;    
    
    //如果count>=50 关闭节点
    if(count>=50){
        ros::shutdown();
    }

    ros::Duration(3).sleep();//发布后先休眠（用于在master中注册）
    while(ros::ok()){
        count++;
        //msg.data="hello";
        std::stringstream ss;
        ss<<"hello -->"<<count;
        msg.data=ss.str();
        if(count<=10){
            pub.publish(msg);
        }
        
        ROS_INFO("publisher: %s",ss.str().c_str());
        rate.sleep();
        ros::spinOnce();//处理回调函数（若有）
        ROS_INFO("spinOnce over !");
    }

    return 0;
}