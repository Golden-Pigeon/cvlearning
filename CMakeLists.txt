cmake_minimum_required(VERSION 3.15)
project(cvlearning)

set(CMAKE_CXX_STANDARD 14)
# set YOUR OWN path or just DELETE it
set(OPENCV_SOURCE D:\\OpenCV\\opencv\\sources\\modules)
set(OpenCV_DIR D:\\OpenCV\\opencv\\build)
# end

add_subdirectory(src)


link_directories(${OPENCV_SOURCE})


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)
target_link_libraries(cvlearning ${OpenCV_LIBS})
