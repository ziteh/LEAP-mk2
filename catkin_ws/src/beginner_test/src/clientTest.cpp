#include <ros/ros.h>
#include <rospy_tutorials/AddTwoInts.h>
#include <cstdlib>

int main(int argc, char** argv)
{
    ros::init(argc, argv,"add_two_ints_client");
    if(argc != 3)
    {
        ROS_INFO("usage: clientTest X Y");
        return 1;
    }
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<rospy_tutorials::AddTwoInts>("add_two_ints");
    
    rospy_tutorials::AddTwoInts srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);

    if(client.call(srv))
    {
        ROS_INFO("Sum: %ld", (long int)srv.response.sum);
    }
    else{
        ROS_INFO("Faild to call service add_two_ints");
        return 1;
    }
    return 0;
}