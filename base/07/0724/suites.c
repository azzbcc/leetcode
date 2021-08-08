/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/28 上午11:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0724.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 7, 3, 6, 5, 6 };
    int target = 3, ans = pivotIndex(arr, LEN(arr));
    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 2, 3 };
    int target = -1, ans = pivotIndex(arr, LEN(arr));
    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}