enable_testing()

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
set(LIBS ${LIBS} ${CHECK_LIBRARIES} roman_clib pthread)

include_directories(. ../src)
add_executable(test_roman check_main.c check_roman_converter_to_roman.c check_roman_converter_to_arabic.c check_roman_numeral_pair.c)
add_test(test_roman ${CMAKE_CURRENT_BINARY_DIR}/test_roman)
target_link_libraries(test_roman ${LIBS})
