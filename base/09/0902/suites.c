/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/18 下午5:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0902.c"

START_TEST(test_official_1) {
    char *digits[] = { "1", "3", "5", "7" };
    int n = 100, target = 20, ans = atMostNGivenDigitSet(digits, LEN(digits), n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *digits[] = { "1", "4", "9" };
    int n = 1000000000, target = 29523, ans = atMostNGivenDigitSet(digits, LEN(digits), n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *digits[] = { "7" };
    int n = 8, target = 1, ans = atMostNGivenDigitSet(digits, LEN(digits), n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    char *digits[] = { "9" };
    int n = 55, target = 1, ans = atMostNGivenDigitSet(digits, LEN(digits), n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    char *digits[] = { "1", "7" };
    int n = 231, target = 10, ans = atMostNGivenDigitSet(digits, LEN(digits), n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}