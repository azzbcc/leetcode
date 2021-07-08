/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/8 下午5:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0930.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 0, 1, 0, 1 }, goal = 2;
    int target = 4, ans = numSubarraysWithSum(arr, LEN(arr), goal);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { 0, 0, 0, 0, 0 }, goal = 0;
    int target = 15, ans = numSubarraysWithSum(arr, LEN(arr), goal);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}