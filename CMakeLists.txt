# Author: Sudeep Pillai (Sep 14, 2014)
project (numpy_opencv_converter)
cmake_minimum_required (VERSION 2.6.0)

# Include package config, boost-python
find_package(PkgConfig REQUIRED)
include(cmake/boost-python.cmake)

# configure opencv
pkg_check_modules(OpenCV opencv)
include_directories(
	${PROJECT_SOURCE_DIR}/include/numpy_opencv_converter/
	${OpenCV_INCLUDE_DIRS}
)

# Build np<=>opencv converter library
boost_python_module(${PROJECT_NAME} src/numpy_opencv_converter.cpp src/conversion.cpp)
target_link_libraries(${PROJECT_NAME} 
	boost_system boost_python 
	${OpenCV_LDFLAGS}
)

# Expose public includes (including OpenCV transitively) to other
# subprojects through cache variable
set(${PROJECT_NAME}_INCLUDE_DIRS 
  ${PROJECT_SOURCE_DIR}/include
  ${OpenCV_INCLUDE_DIRS}
  CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE
)
