cmake_minimum_required(VERSION 3.5)
project(RomanNumeralKataC)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c)
add_executable(RomanNumeralKataC ${SOURCE_FILES})