/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/26 下午3:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0041.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 0 };

    int target = 3, ans = firstMissingPositive(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 4, -1, 1 };

    int target = 2, ans = firstMissingPositive(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int arr[] = { 7, 8, 9, 11, 12 };

    int target = 1, ans = firstMissingPositive(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}