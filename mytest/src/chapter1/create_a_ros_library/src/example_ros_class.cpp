#include <create_a_ros_library/example_ros_class.h>

ExampleRosClass::ExampleRosClass(ros::NodeHandle* nodehandle):nh_(*nodehandle){
    ROS_INFO("in class constructor of ExampleRosClass");
    initializeSubscribers();
    initializePublishers();
    initializeServices();

    val_to_remember_=0.0;
}

void ExampleRosClass::initializeSubscribers()
{
    ROS_INFO("Initializing Subscribers");
    minimal_subscriber_ = nh_.subscribe("example_class_input_topic", 1, &ExampleRosClass::subscriberCallback, this);
}

void ExampleRosClass::initializeServices()
{
    ROS_INFO("Initalizing Services");
    minimal_service_ = nh_.advertiseService("example_minimal_service", &ExampleRosClass::serviceCallback, this);
}

void ExampleRosClass::initializePublishers()
{
    ROS_INFO("Initalizing Publishers");
    minimal_publisher_ = nh_.advertise<std_msgs::Float32>("example_class_output_topic", 1, true);
}

void ExampleRosClass::subscriberCallback(const std_msgs::Float32& message_holder) {
    val_from_subscriber_ = message_holder.data;
    ROS_INFO("myCallback activated: received value %f", val_from_subscriber_);
    std_msgs::Float32 output_msg;
    val_to_remember_ += val_from_subscriber_;
    output_msg.data = val_to_remember_;
    minimal_publisher_.publish(output_msg);
}

bool ExampleRosClass::serviceCallback(std_srvs::TriggerRequest& request, std_srvs::TriggerResponse& response){
    ROS_INFO("service callback activated");
    response.success = true;
    response.message = "here is a response string";
    return true;
}
