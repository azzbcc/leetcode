/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/29 上午8:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0517.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 0, 5 };
    int target = 3, ans = findMinMoves(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 0, 3, 0 };
    int target = 2, ans = findMinMoves(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 0, 2, 0 };
    int target = -1, ans = findMinMoves(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[]  = { 4, 0, 0, 4 };
    int target = 2, ans = findMinMoves(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[]  = { 0, 0, 11, 5 };
    int target = 8, ans = findMinMoves(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}