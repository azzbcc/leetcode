/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/25 下午7:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0845.c"

START_TEST(test_official_1) {
    int arr[] = { 2, 1, 4, 7, 3, 2, 5 };

    int target = 5, ans = longestMountain(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[] = { 2, 2, 2 };

    int target = 0, ans = longestMountain(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int target = 0, ans = longestMountain(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}