cmake_minimum_required(VERSION 3.10)

project(oving4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_executable(oving4 main.cpp)

target_include_directories(oving4 PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_directories(oving4 PRIVATE ${GTKMM_LIBRARY_DIRS})
target_link_libraries(oving4 PRIVATE ${GTKMM_LIBRARIES})
target_compile_options(oving4 PRIVATE ${GTKMM_CFLAGS_OTHER})
