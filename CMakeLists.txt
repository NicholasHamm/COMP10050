cmake_minimum_required(VERSION 3.15)
project(Focus C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Focus
        game_init.c
        game_init.h
        input_output.c
        input_output.h
        main.c)
