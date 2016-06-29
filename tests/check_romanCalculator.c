#include <check.h>
#include <stdlib.h>
#include "../src/romanCalculator.h"

START_TEST(test_one)
    {
        unsigned int value = 1;
        char result[4];

        convertToRoman(value, result);

        ck_assert_str_eq(result, "I");
    }
END_TEST

Suite *romanCalculatorSuite() {
    Suite *suite;
    TCase *testCaseCore;

    suite = suite_create("Roman Calculator");

    testCaseCore = tcase_create("Core");

    tcase_add_test(testCaseCore, test_one);
    suite_add_tcase(suite, testCaseCore);

    return suite;
}

int main() {
    Suite *suite = romanCalculatorSuite();
    SRunner *suiteRunner = srunner_create(suite);

    srunner_run_all(suiteRunner, CK_NORMAL);
    int numberFailed = srunner_ntests_failed(suiteRunner);
    srunner_free(suiteRunner);

    return (numberFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}