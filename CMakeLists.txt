cmake_minimum_required(VERSION 3.2)
project(henry-util)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")

include_directories(.)
include_directories(${PROJECT_SOURCE_DIR}/util/include)
include_directories(/usr/local/include)

link_directories(/usr/local/lib64)

set(LIB_SRC
    util/src/tc_thread_rwlock.cpp
    )

add_library(henry-util SHARED ${LIB_SRC})

set(LIB_LIB
    henry-util
    pthread
    )

add_executable(test_thread_rwlock tests/test_thread_rwlock.cpp)
add_dependencies(test_thread_rwlock  henry-util)
target_link_libraries(test_thread_rwlock  ${LIB_LIB})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

