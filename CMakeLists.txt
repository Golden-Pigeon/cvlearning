cmake_minimum_required(VERSION 3.15)
project(cvlearning)

set(CMAKE_CXX_STANDARD 14)
# set YOUR OWN path or just DELETE it
set(OPENCV_SOURCE D:\\OpenCV\\opencv\\sources\\modules)
set(OpenCV_DIR D:\\OpenCV\\opencv\\build)
# end

link_directories(${OPENCV_SOURCE})


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_libraries(${OpenCV_LIBS})
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

add_subdirectory(src)
