cmake_minimum_required(VERSION 3.0)


project(GameOfLife)

add_subdirectory(mylib)

add_executable(GameOfLife game.c)
add_executable(test test.c)

target_link_libraries(test PRIVATE mylib)
target_link_libraries(test PRIVATE cunit)
target_link_libraries(GameOfLife PRIVATE mylib)