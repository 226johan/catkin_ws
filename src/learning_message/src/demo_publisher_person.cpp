#include"ros/ros.h"
#include"learning_message/Person.h"
/*
    服务通信
    服务端
*/

int main(int argc,char** argv){
    ros::init(argc,argv,"publisher_person");
    
    ros::NodeHandle n;
    ros::Publisher pub=n.advertise<learning_message::Person>("talking",10);
    learning_message::Person person;
    person.name="johan";
    person.age=18;
    person.height=1.70;
    ros::Rate rate(1);
    while(ros::ok()){
        pub.publish(person);
        ROS_INFO("publisher_person: name:%s,age:%d,height:%.2f",person.name.c_str(),person.age,person.height);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}