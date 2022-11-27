/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/27 下午12:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0795.c"

START_TEST(test_official_1) {
    int nums[] = { 2, 1, 4, 3 }, left = 2, right = 3;
    int target = 3, ans = numSubarrayBoundedMax(nums, LEN(nums), left, right);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 2, 9, 2, 5, 6 }, left = 2, right = 8;
    int target = 7, ans = numSubarrayBoundedMax(nums, LEN(nums), left, right);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}