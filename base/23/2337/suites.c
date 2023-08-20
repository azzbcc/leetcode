/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/21 00:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2337.c"

START_TEST(test_official_1) {
    char *start = "_L__R__R_", *target = "L______RR";
    ck_assert_int_eq(true, canChange(start, target));
}

START_TEST(test_official_2) {
    char *start = "R_L_", *target = "__LR";
    ck_assert_int_eq(false, canChange(start, target));
}

START_TEST(test_official_3) {
    char *start = "_R", *target = "R_";
    ck_assert_int_eq(false, canChange(start, target));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}