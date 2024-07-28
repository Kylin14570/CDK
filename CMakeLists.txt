cmake_minimum_required(VERSION 3.22.1)

project(CDK)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/source/*.c)
add_library(CDK ${SRC_FILES})

option(CDK_BUILD_TEST "Build test programs or not" OFF)

IF (CDK_BUILD_TEST)
    add_executable(TestThread ${PROJECT_SOURCE_DIR}/test/TestThread.c)
    target_link_libraries(TestThread CDK)
    add_executable(TestThreadPool ${PROJECT_SOURCE_DIR}/test/TestThreadPool.c)
    target_link_libraries(TestThreadPool CDK)
ENDIF ()