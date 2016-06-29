#include <check.h>
#include <stdlib.h>
#include "check_suites.h"

int main() {
    Suite *suite = roman_calculator_suite();
    SRunner *srunner = srunner_create(suite);

    srunner_run_all(srunner, CK_NORMAL);
    int num_failed = srunner_ntests_failed(srunner);
    srunner_free(srunner);

    return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}