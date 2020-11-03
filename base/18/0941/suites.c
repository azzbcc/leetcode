/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/3 上午11:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0941.c"

START_TEST(test_official_1) {
    int arr[] = { 2, 1 };

    bool target = false, ans = validMountainArray(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 5, 5 };

    bool target = false, ans = validMountainArray(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int arr[] = { 0, 3, 2, 1 };

    bool target = true, ans = validMountainArray(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}