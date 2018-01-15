cmake_minimum_required(VERSION 3.8)
project(json)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES json.cpp json.h jsonTest.cpp)
add_executable(json ${SOURCE_FILES})
target_link_libraries(json ${GTEST_BOTH_LIBRARIES} pthread)