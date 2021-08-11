/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/11 上午11:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0446.c"

START_TEST(test_official_1) {
    int arr[]  = { 2, 4, 6, 8, 10 };
    int target = 7, ans = numberOfArithmeticSlices(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 7, 7, 7, 7, 7 };
    int target = 16, ans = numberOfArithmeticSlices(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_limit) {
    int arr[]  = { 0, 2000000000, -294967296 };
    int target = 0, ans = numberOfArithmeticSlices(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}