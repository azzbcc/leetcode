/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/7 上午10:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0494.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 1, 1, 1, 1 }, t = 3;
    int target = 5, ans = findTargetSumWays(arr, LEN(arr), t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { 1 }, t = 1;
    int target = 1, ans = findTargetSumWays(arr, LEN(arr), t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[] = { 1, 0 }, t = 1;
    int target = 2, ans = findTargetSumWays(arr, LEN(arr), t);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}