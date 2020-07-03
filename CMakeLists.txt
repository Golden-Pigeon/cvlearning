cmake_minimum_required(VERSION 3.15)
project(cvlearning)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

set(OpenCV_DIR D:\\OpenCV\\opencv\\build)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)
target_link_libraries(cvlearning ${OpenCV_LIBS})
