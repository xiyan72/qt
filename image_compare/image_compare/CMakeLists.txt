cmake_minimum_required(VERSION 3.5)

project(image_compare LANGUAGES CXX)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} ${CMAKE_CURRENT_LIST_DIR} )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
aux_source_directory(./ hello_src)
add_executable(image_compare ${hello_src})
target_link_libraries( image_compare  ${OpenCV_LIBS} )
