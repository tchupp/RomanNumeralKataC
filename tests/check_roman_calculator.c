#include <check.h>
#include <roman_calculator.h>

START_TEST(test_single_letter_values)
    {
        char result[4];

        convertToRoman(1, result);
        ck_assert_str_eq(result, "I");

        convertToRoman(5, result);
        ck_assert_str_eq(result, "V");

        convertToRoman(10, result);
        ck_assert_str_eq(result, "X");

        convertToRoman(50, result);
        ck_assert_str_eq(result, "L");

        convertToRoman(100, result);
        ck_assert_str_eq(result, "C");

        convertToRoman(500, result);
        ck_assert_str_eq(result, "D");

        convertToRoman(1000, result);
        ck_assert_str_eq(result, "M");
    }
END_TEST

Suite *roman_calculator_suite() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("Roman Calculator");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_single_letter_values);
    suite_add_tcase(suite, tcase_core);

    return suite;
}