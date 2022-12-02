cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(Ratio)

# file to compile and name of the executable
add_executable(Ratio main.cpp src/Ratio.cpp include/Ratio.hpp)

# include directory
target_include_directories(Ratio PRIVATE "include")

# compilation options
target_compile_features(Ratio PRIVATE cxx_std_17) # use at least c++ 17
if (MSVC)
    target_compile_options(Ratio PRIVATE /W3)
else()
    target_compile_options(Ratio PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

