/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/11 上午8:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0357.c"

START_TEST(test_official_1) {
    int n = 2, target = 91, ans = countNumbersWithUniqueDigits(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 0, target = 1, ans = countNumbersWithUniqueDigits(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_all) {
    int target[] = { 1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851 };
    for (int i = 0; i < LEN(target); ++i) {
        ck_assert_int_eq(countNumbersWithUniqueDigits(i), target[i]);
    }
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_all);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}