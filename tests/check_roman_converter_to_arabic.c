#include <check.h>

#include "check_suites.h"

Suite *roman_converter_to_arabic_suite() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("Roman Converter - To Arabic");

    tcase_core = tcase_create("Core");

    suite_add_tcase(suite, tcase_core);

    return suite;
}