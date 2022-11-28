#include"ros/ros.h"
#include"learning_message/Person.h"
/*
    服务通信
    客户端
*/
void Callback(const learning_message::Person::ConstPtr &person){
    ROS_INFO("subscriber: name:%s,age:%d,height:%.2f",person->name.c_str(),person->age,person->height);


}

int main(int argc,char** argv){

    ros::init(argc,argv,"subscriber_person");
    ros::NodeHandle n;
    ros::Subscriber sub=n.subscribe<learning_message::Person>("talking",10,Callback);


    ros::spin();

    return 0;
}