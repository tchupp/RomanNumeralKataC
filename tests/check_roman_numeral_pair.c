#include <check.h>
#include <roman_numeral_pair.h>

#include "check_suites.h"

START_TEST(test_rn_create)
    {
        RomanNumeralPair *rn_pair = new_rn_pair(900, "CM");

        ck_assert_int_eq(900, get_arabic(rn_pair));
        ck_assert_str_eq("CM", get_roman(rn_pair));

        free_rn_pair(rn_pair);
    }
END_TEST

Suite *roman_numeral_pair_suite() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("Roman Numeral Pair");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_rn_create);
    suite_add_tcase(suite, tcase_core);

    return suite;
}
