cmake_minimum_required(VERSION 2.8)

project(visitor)

if (MSVC)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON) # turn on using solution folders
endif()

add_subdirectory(docu_generator)

add_executable(visitor visitor.h main.cpp)
