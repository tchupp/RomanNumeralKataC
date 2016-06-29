#include <check.h>
#include <roman_converter.h>

#include "check_suites.h"

START_TEST(test_single_letter_values)
    {
        char result[1];

        convert_to_roman(1, result);
        ck_assert_str_eq(result, "I");

        convert_to_roman(5, result);
        ck_assert_str_eq(result, "V");

        convert_to_roman(10, result);
        ck_assert_str_eq(result, "X");

        convert_to_roman(50, result);
        ck_assert_str_eq(result, "L");

        convert_to_roman(100, result);
        ck_assert_str_eq(result, "C");

        convert_to_roman(500, result);
        ck_assert_str_eq(result, "D");

        convert_to_roman(1000, result);
        ck_assert_str_eq(result, "M");
    }
END_TEST

Suite *roman_converter_suite() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("Roman Converter");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_single_letter_values);
    suite_add_tcase(suite, tcase_core);

    return suite;
}