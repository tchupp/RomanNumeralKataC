#include <check.h>
#include <roman_converter.h>

#include "check_suites.h"

START_TEST(test_lower_values_on_right_for_addition)
    {
        char result[2];

        convert_to_roman(1000, result);
        ck_assert_str_eq(result, "M");

        convert_to_roman(501, result);
        ck_assert_str_eq(result, "DI");

        convert_to_roman(105, result);
        ck_assert_str_eq(result, "CV");

        convert_to_roman(60, result);
        ck_assert_str_eq(result, "LX");

        convert_to_roman(1011, result);
        ck_assert_str_eq(result, "MXI");

        convert_to_roman(666, result);
        ck_assert_str_eq(result, "DCLXVI");
    }
END_TEST

START_TEST(test_lower_values_are_subtracted_instead_of_repeated)
    {
        char result[2];

        convert_to_roman(3, result);
        ck_assert_str_eq(result, "III");

        convert_to_roman(4, result);
        ck_assert_str_eq(result, "IV");

        convert_to_roman(9, result);
        ck_assert_str_eq(result, "IX");

        convert_to_roman(38, result);
        ck_assert_str_eq(result, "XXXVIII");

        convert_to_roman(39, result);
        ck_assert_str_eq(result, "XXXIX");

        convert_to_roman(40, result);
        ck_assert_str_eq(result, "XL");

        convert_to_roman(90, result);
        ck_assert_str_eq(result, "XC");

        convert_to_roman(400, result);
        ck_assert_str_eq(result, "CD");

        convert_to_roman(900, result);
        ck_assert_str_eq(result, "CM");
    }
END_TEST

START_TEST(test_values_can_repeat)
    {
        char result[2];

        convert_to_roman(3000, result);
        ck_assert_str_eq(result, "MMM");

        convert_to_roman(303, result);
        ck_assert_str_eq(result, "CCCIII");

        convert_to_roman(120, result);
        ck_assert_str_eq(result, "CXX");

        convert_to_roman(73, result);
        ck_assert_str_eq(result, "LXXIII");

        convert_to_roman(27, result);
        ck_assert_str_eq(result, "XXVII");

        convert_to_roman(777, result);
        ck_assert_str_eq(result, "DCCLXXVII");
    }
END_TEST

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

    tcase_add_test(tcase_core, test_lower_values_on_right_for_addition);
    tcase_add_test(tcase_core, test_lower_values_are_subtracted_instead_of_repeated);
    tcase_add_test(tcase_core, test_values_can_repeat);
    tcase_add_test(tcase_core, test_single_letter_values);
    suite_add_tcase(suite, tcase_core);

    return suite;
}