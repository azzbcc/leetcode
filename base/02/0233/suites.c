/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/13 上午10:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0233.c"

START_TEST(test_official_1) {
    int n      = 13;
    int target = 6, ans = countDigitOne(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 0;
    int target = 0, ans = countDigitOne(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int n      = 213;
    int target = 146, ans = countDigitOne(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int n      = 100;
    int target = 21, ans = countDigitOne(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int n      = 101;
    int target = 23, ans = countDigitOne(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_3) {
    int n      = 1000000000;
    int target = 900000001, ans = countDigitOne(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}