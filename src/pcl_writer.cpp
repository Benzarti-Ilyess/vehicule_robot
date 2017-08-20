#include<ros/ros.h>
#include<pcl/point_cloud.h>
#include<pcl_conversions/pcl_conversions.h>
#include<sensor_msgs/PointCloud2.h>
#include<sensor_msgs/PointCloud.h>
#include<sensor_msgs/point_cloud_conversion.h>
#include<pcl/io/pcd_io.h>

void saving_point_clouds(const sensor_msgs::PointCloud & input)
{
 
 sensor_msgs::PointCloud2 input1;

pcl::PointCloud<pcl::PointXYZ> cloud;
convertPointCloudToPointCloud2(input,input1);
pcl::fromROSMsg(input1,cloud);
pcl::io::savePCDFileASCII("save_point_clouds.pcd",cloud);


}

int main(int argc, char**argv)
{

ros::init(argc,argv,"pcl_writer");
ros::NodeHandle nh;
ros::Subscriber pcl_sub = nh.subscribe("lidar_points",10,saving_point_clouds);
ros::spin();





	return 0;
}