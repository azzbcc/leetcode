/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/1 上午11:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0486.c"

START_TEST(test_official_1) {
    int arr[]   = { 1, 5, 2 };
    bool target = false, ans = PredictTheWinner(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[]   = { 1, 5, 233, 7 };
    bool target = true, ans = PredictTheWinner(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int arr[]   = { 1, 3, 1 };
    bool target = false, ans = PredictTheWinner(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}