#include<iostream>
#include<ros/ros.h>
#include<pcl/visualization/cloud_viewer.h>
#include<sensor_msgs/PointCloud2.h>
#include<pcl_conversions/pcl_conversions.h>
#include<sensor_msgs/PointCloud.h>
#include<sensor_msgs/point_cloud_conversion.h>
class cloudHandler
{
public:
cloudHandler():viewer("Cloud Viewer")
{
pcl_sub	=nh.subscribe("lidar_points",10,&cloudHandler::cloud_sub,this);
viewer_timer=nh.createTimer(ros::Duration(0.1),&cloudHandler::timer_sub,this);
}
void cloud_sub(const sensor_msgs::PointCloud &input)
{
	sensor_msgs::PointCloud2 input1;
pcl::PointCloud<pcl::PointXYZ> cloud;
convertPointCloudToPointCloud2(input,input1);
pcl::fromROSMsg(input1,cloud);
viewer.showCloud(cloud.makeShared());
}
void timer_sub(const ros::TimerEvent&)
{

if(viewer.wasStopped())
{
ros::shutdown();
}

}
protected:
ros::NodeHandle	nh;
ros::Subscriber	pcl_sub;
pcl::visualization::CloudViewer	viewer;
ros::Timer viewer_timer;

};
main(int argc,char **argv)
{
ros::init(argc,argv,"pcl_visualizer_gazebo");
cloudHandler handler;
ros::spin();
return	0;
}