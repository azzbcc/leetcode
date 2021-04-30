/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/30 下午5:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0137.c"

START_TEST(test_official_1) {
    int arr[]  = { 2, 2, 3, 2 };
    int target = 3, ans = singleNumber(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 0, 1, 0, 1, 0, 1, 99 };
    int target = 99, ans = singleNumber(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]  = { -2, -2, 1, 1, 4, 1, 4, 4, -4, -2 };
    int target = -4, ans = singleNumber(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}