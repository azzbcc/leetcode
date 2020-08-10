/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/10 下午7:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>
#include <stdbool.h>

#include "0026.c"

START_TEST(test_official_1) {
    int arr[]        = { 1, 1, 2 };
    int arr_target[] = { 1, 2 };

    int target = 2, ans = removeDuplicates(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
    ck_assert_mem_eq(arr, arr_target, sizeof(target));
}

START_TEST(test_official_2) {
    int arr[]        = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int arr_target[] = { 0, 1, 2, 3, 4 };

    int target = 5, ans = removeDuplicates(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
    ck_assert_mem_eq(arr, arr_target, sizeof(target));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}