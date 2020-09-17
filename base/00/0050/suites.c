/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/17 下午12:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0050.c"

START_TEST(test_official_1) {
    double x = 2, n = 10;
    ck_assert_double_eq(pow(x, n), myPow(x, n));
}

START_TEST(test_official_2) {
    double x = 2.1, n = 3;
    ck_assert_double_eq(pow(x, n), myPow(x, n));
}

START_TEST(test_official_3) {
    double x = 2, n = -2;
    ck_assert_double_eq(pow(x, n), myPow(x, n));
}

START_TEST(test_own) {
    double x = 2, n = -5;
    ck_assert_double_eq(pow(x, n), myPow(x, n));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}