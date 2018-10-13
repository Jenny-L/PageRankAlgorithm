cmake_minimum_required(VERSION 3.12)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab4 main.cpp matrix.hpp matrix.cpp connectivitymatrix.cpp connectivitymatrix.hpp rankingalgorythm.cpp rankingalgorythm.hpp)