cmake_minimum_required(VERSION 3.5)
project(RomanNumeralKataC)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES src/main.c src/romanCalculator.c src/romanCalculator.h)
add_executable(RomanNumeralKataC ${SOURCE_FILES})

set(TEST_FILES  tests/check_romanCalculator.c)
add_executable(RomanNumeralKataCTest ${TEST_FILES})
