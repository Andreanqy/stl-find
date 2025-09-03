cmake_minimum_required(VERSION 3.22)
project(stl-find LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stlfind src/main.cpp)
target_compile_features(stlfind PRIVATE cxx_std_20)
