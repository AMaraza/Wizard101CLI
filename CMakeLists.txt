cmake_minimum_required(VERSION 3.30)
project(Wiz101)

set(CMAKE_CXX_STANDARD 26)

add_executable(Wiz101 main.cpp
        headers/spells.h
        headers/combat.h)
