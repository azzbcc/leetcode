/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/15 下午2:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1846.c"

START_TEST(test_official_1) {
    int arr[]  = { 2, 2, 1, 2, 1 };
    int target = 2, ans = maximumElementAfterDecrementingAndRearranging(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 100, 1, 1000 };
    int target = 3, ans = maximumElementAfterDecrementingAndRearranging(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 1, 2, 3, 4, 5 };
    int target = 5, ans = maximumElementAfterDecrementingAndRearranging(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}