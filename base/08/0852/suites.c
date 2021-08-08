/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/15 下午2:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0852.c"

START_TEST(test_official_1) {
    int arr[]  = { 0, 1, 0 };
    int target = 1, ans = peakIndexInMountainArray(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 0, 2, 1, 0 };
    int target = 1, ans = peakIndexInMountainArray(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 0, 10, 5, 2 };
    int target = 1, ans = peakIndexInMountainArray(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[]  = { 3, 4, 5, 1 };
    int target = 2, ans = peakIndexInMountainArray(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int arr[]  = { 24, 69, 100, 99, 79, 78, 67, 36, 26, 19 };
    int target = 2, ans = peakIndexInMountainArray(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}