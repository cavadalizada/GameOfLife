cmake_minimum_required(VERSION 3.0)

project(GameOfLife)

add_subdirectory(mylib)

add_executable(GameOfLife game.c)

target_link_libraries(GameOfLife PRIVATE mylib)