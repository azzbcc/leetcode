/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/15 下午7:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "17_04.c"

START_TEST(test_official_1) {
    int arr[]  = { 3, 0, 1 };
    int target = 2, ans = missingNumber(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[]  = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
    int target = 8, ans = missingNumber(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}