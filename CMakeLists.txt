cmake_minimum_required(VERSION 3.1)
project(clion_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build)

set(SRCS_DIR $ENV{CPP_BCOSTA})

include_directories(${SRCS_DIR})

file(GLOB_RECURSE CORE_SRCS ${SRCS_DIR}/core/*.cpp)
file(GLOB_RECURSE CORE_HDRS ${SRCS_DIR}/core/*.h)
list(REMOVE_ITEM CORE_SRCS ${SRCS_DIR}/core/_string.cpp)

file(GLOB_RECURSE PLATFORM_SRCS ${SRCS_DIR}/platform/*.cpp)
file(GLOB_RECURSE PLATFORM_HDRS ${SRCS_DIR}/platform/*.h)

if (MINGW)
    list(REMOVE_ITEM CORE_SRCS ${SRCS_DIR}/core/win32/time.cpp)
    list(REMOVE_ITEM PLATFORM_SRCS ${SRCS_DIR}/platform/win/io.cpp)
else()
    list(REMOVE_ITEM PLATFORM_SRCS ${SRCS_DIR}/platform/linux/io.cpp)
endif()

add_library(core ${CORE_SRCS} ${CORE_HDRS})
add_library(platform ${CORE_SRCS} ${CORE_HDRS})

set(SOURCE_FILES main.cpp)
add_executable(clion_test ${SOURCE_FILES})
target_link_libraries(clion_test core platform)