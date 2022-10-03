/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/3 上午8:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0829.c"

START_TEST(test_official_1) {
    int n      = 5;
    int target = 2, ans = consecutiveNumbersSum(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 9;
    int target = 3, ans = consecutiveNumbersSum(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n      = 15;
    int target = 4, ans = consecutiveNumbersSum(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}