cmake_minimum_required(VERSION 3.23)

project(SimpleCalc)

set(CMAKE_CXX_STANDARD 17)


target_include_directories(main
    PRIVATE include
)


add_executable(main app/main.cpp)