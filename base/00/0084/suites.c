/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/10 下午5:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0084.c"

START_TEST(test_official) {
    int arr[] = { 2, 1, 5, 6, 2, 3 };

    int target = 10, ans = largestRectangleArea(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[] = { 0, 9 };

    int target = 9, ans = largestRectangleArea(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[] = { 5, 4, 1, 2 };

    int target = 8, ans = largestRectangleArea(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official);
}