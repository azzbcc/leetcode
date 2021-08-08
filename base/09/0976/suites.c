/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/29 下午2:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0976.c"

START_TEST(test_official_1) {
    int arr[]  = { 2, 1, 2 };
    int target = 5, ans = largestPerimeter(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 2, 1 };
    int target = 0, ans = largestPerimeter(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 3, 2, 3, 4 };
    int target = 10, ans = largestPerimeter(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[]  = { 3, 6, 2, 3 };
    int target = 8, ans = largestPerimeter(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]  = { 2, 6, 2, 5, 4, 15, 1 };
    int target = 15, ans = largestPerimeter(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}