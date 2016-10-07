#include <check.h>
#include <roman_converter_utils.h>

#include "check_suites.h"

START_TEST(test)
    {
        ck_assert_int_eq(13, NUM_PAIRS);
    }
END_TEST

Suite *roman_converter_utils_suite() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("Roman Converter - Utils");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test);

    suite_add_tcase(suite, tcase_core);

    return suite;
}
