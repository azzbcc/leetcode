/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/3 上午11:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0805.c"

START_TEST(test_official) {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    bool target = true, ans = splitArraySameAverage(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_own) {
    int arr[] = { 0, 0, 0, 0, 0, 3, 4 };

    bool target = true, ans = splitArraySameAverage(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int arr[] = { 6, 8, 18, 3, 1 };

    bool target = false, ans = splitArraySameAverage(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_tle) {
    int arr[] = { 60, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
                  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30 };

    bool target = false, ans = splitArraySameAverage(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}