cmake_minimum_required(VERSION 3.15)
project(TODO-List C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(my_linked_list libs/linked_list.c)

add_library(my_strlib libs/my_strlib.c)

add_library(list_permanence libs/list_permanency.c)

target_include_directories(my_linked_list PUBLIC libs)

target_include_directories(my_strlib PUBLIC libs)

target_include_directories(list_permanence PUBLIC libs)

set(CMAKE_C_STANDARD 17)

add_executable(TODO-List main.c)

target_link_libraries(TODO-List PRIVATE my_linked_list)

target_link_libraries(TODO-List PRIVATE my_strlib)

target_link_libraries(TODO-List PRIVATE list_permanence)


