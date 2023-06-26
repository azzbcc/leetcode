/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/26 16:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2485.c"

START_TEST(test_official_1) {
    int n = 8, target = 6;
    ck_assert_int_eq(target, pivotInteger(n));
}

START_TEST(test_official_2) {
    int n = 1, target = 1;
    ck_assert_int_eq(target, pivotInteger(n));
}

START_TEST(test_official_3) {
    int n = 4, target = -1;
    ck_assert_int_eq(target, pivotInteger(n));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}