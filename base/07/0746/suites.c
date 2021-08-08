/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/21 上午11:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0746.c"

START_TEST(test_official_1) {
    int arr[]  = { 10, 15, 20 };
    int target = 15, ans = minCostClimbingStairs(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    int target = 6, ans = minCostClimbingStairs(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}