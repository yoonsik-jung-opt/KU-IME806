cmake_minimum_required(VERSION 3.21)
project(IME806)
set(TARGET_NAME IME806)

set(CMAKE_CXX_STANDARD 14)

add_executable(IME806 main.cpp pch.h gd.h steepestdescent.h newtonstep.h matmul.h)