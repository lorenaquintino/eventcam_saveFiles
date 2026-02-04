cmake_minimum_required(VERSION 3.10)

project(MetavisionRecorder)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "/workspace_eventcam/openeb") 

find_package(MetavisionSDK COMPONENTS core  stream REQUIRED)

add_executable(simple_recorder main.cpp helper.h)

target_link_libraries(simple_recorder PRIVATE MetavisionSDK::core MetavisionSDK::stream)
