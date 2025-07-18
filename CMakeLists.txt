cmake_minimum_required(VERSION 3.10)
project(LungCT_Segmentation)

find_package(OpenCV REQUIRED)
include_directories(include)

add_executable(lung_ct
    src/main.cpp
    src/segmentation.cpp
)
target_link_libraries(lung_ct ${OpenCV_LIBS})
