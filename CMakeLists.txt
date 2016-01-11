# Author: Sudeep Pillai (Sep 14, 2014)
project (numpy_opencv_converter)
cmake_minimum_required (VERSION 2.6.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpic")

find_package(Boost REQUIRED COMPONENTS system python)
find_package(OpenCV REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}/include/numpy_opencv_converter/
  ${Boost_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIR}
  ${PYTHON_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} src/numpy_opencv_converter.cpp src/conversion.cpp)
target_link_libraries(${PROJECT_NAME} 
  ${Boost_LIBRARIES}
  ${OpenCV_LIBS}
  ${PYTHON_LIBRARIES}
)

# Expose public includes (including dependencies transitively) to other
# subprojects through cache variable
set(${PROJECT_NAME}_INCLUDE_DIRS 
  ${PROJECT_SOURCE_DIR}/include
  ${Boost_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIR}
  ${PYTHON_INCLUDE_DIRS}
  CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE
)
