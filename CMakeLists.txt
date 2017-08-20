cmake_minimum_required(VERSION 2.8.3)
project(vehicle_robot)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg image_transport cv_bridge pcl_conversions
  pcl_msgs
  pcl_ros
  sensor_msgs)


find_package(PCL REQUIRED)







##generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()
include_directories(include ${catkin_INCLUDE_DIRS} ${OpenCV_LIBRARIES} ${PCL_INCLUDE_DIRS})


link_directories(${PCL_LIBRARY_DIRS})

add_executable(pcl_reader src/pcl_reader.cpp)
target_link_libraries(pcl_reader ${catkin_LIBRARIES} ${PCL_LIBRARIES})

add_executable(pcl_writer src/pcl_writer.cpp)
target_link_libraries(pcl_writer ${catkin_LIBRARIES} ${PCL_LIBRARIES})

add_executable(opencv_demo src/opencv_demo.cpp)
target_link_libraries(opencv_demo ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(opencv_demo vehicle_robot_generate_messages_cpp)


add_executable(edge_detection_gazebo src/edge_detection_gazebo.cpp)
target_link_libraries(edge_detection_gazebo ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(edge_detection_gazebo vehicle_robot_generate_messages_cpp)
