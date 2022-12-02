#include"ros/ros.h"
#include"learning_head_src/hello.h"

/*
    注意cmakelist的配置
    1.头文件和源文件的配置
    include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    )

    2.声明c++库
    add_library(head_src
    include/${PROJECT_NAME}/hello.h
    src/hello.cpp
    )

    add_dependencies(head_src ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
    add_dependencies(demo_usehello ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

    target_link_libraries(head_src
    ${catkin_LIBRARIES}
    )

    可执行文件配置时包含之前设置的head库，此处为head_src
    target_link_libraries(demo_usehello
    head_src
    ${catkin_LIBRARIES}
    )
*/

int main(int argc,char** argv){
    ros::init(argc,argv,"hello_head_src");
    hello_ns::MyHello myhello;
    myhello.run();

    return 0;
}