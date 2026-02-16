cmake_minimum_required(VERSION 3.23)

project(Bot)

# CMAKE_CXX_STANDARD - variable, describing c-standart (ex: 11, 17, 20)
set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTS "Build tests" OFF) 

# where to put bin files (build/bin/program)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# where to put static libraries (build/lib/<our_lib_name>.a)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# where to put dynamic libraries (build/lib/<our_lib_name>.so) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# just creating library
#_start
add_library(bot_utils
    utils/src/test.cpp
)

# we tell compiler "headlines lie in folder include"
target_include_directories(bot_utils
    PUBLIC utils/include      # link lib and headline, PUBLIC because we will need this header later (48 line)
)
#_end

#from start to end is library (.cpp + .hpp)

# сompile the program named "program" from the file app/main.cpp
add_executable(program 
    bot/app/main.cpp)

target_link_libraries(program PRIVATE bot_utils)  # PRIVATE because we don`t want access to the lib from program

if (BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(   
        Catch2                                                # declare dependency catch2 from        
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git # where to download
        GIT_TAG v3.4.0                                        # version
    )
    FetchContent_MakeAvailable(Catch2)                        # download catch2 into build, add as a part of assembley, create targets type Catch2::Catch2WithMain

    enable_testing()                                          # enables support for tests in CMake/CTest for add_test (67) could work
    
#     # сompile the program named "tests" from the file tests/test.cpp
    add_executable(tests 
        tests/test_test.cpp
    )

#     # connect out library and Catch2 to the tests program
    target_link_libraries(tests PRIVATE bot_utils Catch2::Catch2WithMain)

#     # register and run tests executable with CTest
    add_test(NAME TestsStrModesFunction COMMAND $<TARGET_FILE:tests>) 
endif()
