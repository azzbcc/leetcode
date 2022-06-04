/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/4 下午12:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "102.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 1, 1, 1, 1 }, key = 3;
    int target = 5, ans = findTargetSumWays(nums, LEN(nums), key);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1 }, key = 1;
    int target = 1, ans = findTargetSumWays(nums, LEN(nums), key);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}