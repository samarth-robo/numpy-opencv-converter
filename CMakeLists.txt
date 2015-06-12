# Author: Sudeep Pillai (Sep 14, 2014)
project (numpy-opencv-converter)
cmake_minimum_required (VERSION 2.6.0)

# Include package config, boost-python
find_package(PkgConfig REQUIRED)
include(cmake/boost-python.cmake)

# configure opencv
#pkg_check_modules(OpenCV opencv)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

message("PYTHON_INCLUDE_DIRS: " ${PYTHON_INCLUDE_DIRS})
message("PYTHON_LIBRARIES: " ${PYTHON_LIBRARIES})

# Build np<=>opencv converter library
boost_python_module(np_opencv_converter np_opencv_converter.cpp utils/conversion.cpp)
target_link_libraries(np_opencv_converter boost_system boost_python ${OpenCV_LIBS})

# Build test library
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
boost_python_module(np_opencv_module tests/np_opencv_module.cpp)
target_link_libraries(np_opencv_module boost_system boost_python np_opencv_converter ${OpenCV_LIBS})

boost_python_module(rgb_test_module tests/rgb_test_module.cpp)
target_link_libraries(rgb_test_module boost_system boost_python np_opencv_converter ${OpenCV_LIBS})
