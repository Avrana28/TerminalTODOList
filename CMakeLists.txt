cmake_minimum_required(VERSION 3.15)
project(TODO-List C)

add_library(my_linked_list libs/linked_list.c)

target_include_directories(my_linked_list PUBLIC libs)

set(CMAKE_C_STANDARD 17)

add_executable(TODO-List main.c)

target_link_libraries(TODO-List PRIVATE my_linked_list)
