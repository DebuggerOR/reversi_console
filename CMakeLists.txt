cmake_minimum_required(VERSION 3.12)
project(reversi100)

set(CMAKE_CXX_STANDARD 14)

add_executable(reversi100 board.cpp cell.cpp main.cpp manager.cpp player.cpp human.cpp)