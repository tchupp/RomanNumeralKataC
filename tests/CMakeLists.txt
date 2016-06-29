enable_testing()

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
set(LIBS ${LIBS} ${CHECK_LIBRARIES} roman_clib)

include_directories(. ../src)
add_executable(testRoman check_romanCalculator.c)
add_test(testRoman ${CMAKE_CURRENT_BINARY_DIR}/testRoman)
target_link_libraries(testRoman ${LIBS})
