cmake_minimum_required(VERSION 3.1)
project(clion_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build)

set(SRCS_DIR F:/sources/c++)

include_directories(${SRCS_DIR})

file(GLOB_RECURSE CORE_MATH_SRCS ${SRCS_DIR}/core/math/*.cpp)

add_library(
    core
    ${SRCS_DIR}/core/string.cpp
    ${CORE_MATH_SRCS}
)

set(SOURCE_FILES main.cpp)
add_executable(clion_test ${SOURCE_FILES})
target_link_libraries(clion_test core)