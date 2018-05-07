cmake_minimum_required(VERSION 2.8.0)

project(iterator)

if (MSVC)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON) # turn on using solution folders
endif()

set(SRCS
    main.cpp
    )

set(HDRS
    iterator_t.hpp
    )
add_executable(test_iterator ${SRCS} ${HDRS})