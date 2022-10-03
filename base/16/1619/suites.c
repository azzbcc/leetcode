/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/9/14 下午12:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1619.c"

START_TEST(test_official_1) {
    int arr[]     = { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 };
    double target = 2.00000, ans = trimMean(arr, LEN(arr));
    ck_assert_double_eq_tol(ans, target, 0.00001);
}

START_TEST(test_official_2) {
    int arr[]     = { 6, 2, 7, 5, 1, 2, 0, 3, 10, 2, 5, 0, 5, 5, 0, 8, 7, 6, 8, 0 };
    double target = 4.00000, ans = trimMean(arr, LEN(arr));
    ck_assert_double_eq_tol(ans, target, 0.00001);
}

START_TEST(test_official_3) {
    int arr[]     = { 6, 0, 7, 0, 7, 5, 7, 8, 3,  4, 0, 7, 8, 1, 6, 8,  1, 1, 2, 4,
                      8, 1, 9, 5, 4, 3, 8, 5, 10, 8, 6, 6, 1, 0, 6, 10, 8, 2, 3, 4 };
    double target = 4.77778, ans = trimMean(arr, LEN(arr));
    ck_assert_double_eq_tol(ans, target, 0.00001);
}

START_TEST(test_official_4) {
    int arr[]     = { 9, 7, 8,  7, 7,  8, 4, 4,  6, 8, 8, 7, 6, 8, 8, 9, 2, 6, 0, 0, 1, 10, 8, 6, 3, 3, 5, 1, 10, 9,
                      0, 7, 10, 0, 10, 4, 1, 10, 6, 9, 3, 6, 0, 0, 2, 7, 0, 6, 7, 2, 9, 7,  7, 3, 0, 1, 6, 1, 10, 3 };
    double target = 5.27778, ans = trimMean(arr, LEN(arr));
    ck_assert_double_eq_tol(ans, target, 0.00001);
}

START_TEST(test_official_5) {
    int arr[]     = { 4,  8, 4,  10, 0, 7, 1, 3, 7, 8,  8,  3, 4, 1,  6, 2, 1, 1, 8,  0, 9, 8, 0, 3, 9,  10, 3,
                      10, 1, 10, 7,  3, 2, 1, 4, 9, 10, 7,  6, 4, 0,  8, 5, 1, 2, 1,  6, 2, 5, 0, 7, 10, 9,  10,
                      3,  7, 10, 5,  8, 5, 7, 6, 7, 6,  10, 9, 5, 10, 5, 5, 7, 2, 10, 7, 7, 8, 2, 0, 1,  1 };
    double target = 5.29167, ans = trimMean(arr, LEN(arr));
    ck_assert_double_eq_tol(ans, target, 0.00001);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}