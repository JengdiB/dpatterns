cmake_minimum_required(VERSION 2.8.0)

project(dpatterns)
if (MSVC)
    #turn on using solution folders
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

add_subdirectory(iterator)
add_subdirectory(visitor)
