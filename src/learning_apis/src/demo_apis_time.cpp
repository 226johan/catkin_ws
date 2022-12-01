#include"ros/ros.h"


/*
    需求1：演示时间相关操作（获取当前时刻+设置制定时刻）
    实现：
        1.准备（头文件，节点初始化，NodeHandle创建）
        2.获取当前时刻
        3.设置制定时刻

    需求2：程序执行中停顿5秒
    实现：
        1.创建持续时间对象
        2.休眠
    
    需求3：已知程序开始运行时的时刻和程序运行的时间，秋运行结束的时刻
    实现：
        1.获取开始执行的时刻
        2.模拟运行时间（N秒）
        3.计算结束时刻 = 开始 + 持续时间
    注意：
        1.时刻与持续时间可以执行加减
        2.持续时间之间可以执行加减
        3.时刻之间只可以相减，不可以相加

    需求4：每隔一秒钟，在控制台输出一段文本
    实现：
        策略1：ros::Rate()
        策略2：定时器
    注意：
        创建： n.createRimer()
        参数1：时间间隔
        参数2：回调函数（时间事件 TimeEvent）
        参数3：是否只执行一次
        参数4：是否自动启动（当设置为fales 需要手动调用 timer.start())

        定时器使用后要使用 ros::spin()
*/

void Callback(const ros::TimerEvent& event){
    ROS_INFO("here is timer");
    //获取函数被调用的时刻
    ROS_INFO("time now:%.2f",event.last_real.toSec());
}



int main(int argc,char** argv){
    ros::init(argc,argv,"apis_time");
    ros::NodeHandle n;//若不创建节点初始化句柄，会导致时间API调用失败
    //now函数会将当前时刻封装并返回
    //当前时刻：now被调用执行的那一刻
    //参考系：1970年01月01日 00：00：00
    ros::Time right_now = ros::Time::now();
    ROS_INFO("right_now: %.2f",right_now.toSec());
    ROS_INFO("right_now: %d",right_now.sec);
    //设置指定时刻
    ros::Time t1(20,312345678);
    ROS_INFO("t1 = %.2f",t1.toSec());
    ros::Time t2(100.35);
    ROS_INFO("t2 = %.2f",t2.toSec());
    

    ROS_INFO("-------------Duration of time---------------");
    ros::Time start = ros::Time::now();
    ROS_INFO("sleep start ! time is:%.2f",start.toSec());
    ros::Duration du(4.5);
    du.sleep();
    ros::Time end = ros::Time::now();
    ROS_INFO("sleep over ! time is:%.2f",end.toSec());
    
    
    ROS_INFO("------------Operation of time---------------");
    // 1.获取开始执行的时刻
    ros::Time begin = ros::Time::now();
    // 2.模拟运行时间（N秒）
    ros::Duration du1(5);
    // 3.计算结束时刻 = 开始 + 持续时间
    ros::Time stop=begin+du1;
    ROS_INFO("strat time is:%.2f",begin.toSec());
    ROS_INFO("stop time is:%.2f",stop.toSec());


    ROS_INFO("-------------------timer--------------------");
    /*ros::Timer createTimer(ros::Duration period,        //时间间隔  ---1s
                    const ros::TimerCallback &callback,   //回调函数  ---封装业务
                    bool oneshot = false,                 //是否是一次性
                    bool autostart = true)                //自动启动
    */
    //ros::Timer timer= n.createTimer(ros::Duration(1),Callback);
    //ros::Timer timer= n.createTimer(ros::Duration(1),Callback,true);  
    ros::Timer timer= n.createTimer(ros::Duration(1),Callback,false,false);
    timer.start();//手动启动
    ros::spin();
    return 0;

}