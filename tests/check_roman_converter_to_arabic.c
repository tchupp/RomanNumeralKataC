#include <check.h>
#include <roman_converter.h>

#include "check_suites.h"

START_TEST(test)
    {
        unsigned int result;

        result = convert_to_arabic("M");
        ck_assert_int_eq(1000, result);
    }
END_TEST

Suite *roman_converter_to_arabic_suite() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("Roman Converter - To Arabic");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test);

    suite_add_tcase(suite, tcase_core);

    return suite;
}