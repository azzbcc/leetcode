/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/27 14:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1186.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, -2, 0, 3 };
    int target = 4, ans = maximumSum(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, -2, -2, 3 };
    int target = 3, ans = maximumSum(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { -1, -1, -1, -1 };
    int target = -1, ans = maximumSum(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}