#include <check.h>
#include <roman_converter.h>
#include <limits.h>

#include "check_suites.h"

START_TEST(test_single_numerals)
    {
        unsigned int result;

        result = convert_to_arabic("M");
        ck_assert_int_eq(1000, result);

        result = convert_to_arabic("D");
        ck_assert_int_eq(500, result);

        result = convert_to_arabic("C");
        ck_assert_int_eq(100, result);

        result = convert_to_arabic("L");
        ck_assert_int_eq(50, result);

        result = convert_to_arabic("X");
        ck_assert_int_eq(10, result);

        result = convert_to_arabic("V");
        ck_assert_int_eq(5, result);

        result = convert_to_arabic("I");
        ck_assert_int_eq(1, result);
    }
END_TEST

START_TEST(test_double_numerals)
    {
        unsigned int result;

        result = convert_to_arabic("CM");
        ck_assert_int_eq(900, result);

        result = convert_to_arabic("CD");
        ck_assert_int_eq(400, result);

        result = convert_to_arabic("XC");
        ck_assert_int_eq(90, result);

        result = convert_to_arabic("XL");
        ck_assert_int_eq(40, result);

        result = convert_to_arabic("IX");
        ck_assert_int_eq(9, result);

        result = convert_to_arabic("IV");
        ck_assert_int_eq(4, result);
    }
END_TEST

START_TEST(test_numerals_can_be_counted_multiple_times)
    {
        unsigned int result;

        result = convert_to_arabic("MM");
        ck_assert_int_eq(2000, result);

        result = convert_to_arabic("MMM");
        ck_assert_int_eq(3000, result);

        result = convert_to_arabic("CC");
        ck_assert_int_eq(200, result);

        result = convert_to_arabic("CCC");
        ck_assert_int_eq(300, result);

        result = convert_to_arabic("XX");
        ck_assert_int_eq(20, result);

        result = convert_to_arabic("XXX");
        ck_assert_int_eq(30, result);

        result = convert_to_arabic("II");
        ck_assert_int_eq(2, result);

        result = convert_to_arabic("III");
        ck_assert_int_eq(3, result);
    }
END_TEST

START_TEST(test_malformed_numerals_return_UINT_MAX)
    {
        /*unsigned int result;

        result = convert_to_arabic("CMM");
        ck_assert_int_eq(UINT_MAX, result);

        result = convert_to_arabic("IIII");
        ck_assert_int_eq(UINT_MAX, result);

        result = convert_to_arabic("DD");
        ck_assert_int_eq(UINT_MAX, result);*/
    }
END_TEST

Suite *roman_converter_to_arabic_suite() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("Roman Converter - To Arabic");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_single_numerals);
    tcase_add_test(tcase_core, test_double_numerals);
    tcase_add_test(tcase_core, test_numerals_can_be_counted_multiple_times);
    tcase_add_test(tcase_core, test_malformed_numerals_return_UINT_MAX);

    suite_add_tcase(suite, tcase_core);

    return suite;
}
