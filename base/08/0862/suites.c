/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/26 上午11:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0862.c"

START_TEST(test_official_1) {
    int nums[] = { 1 }, k = 1;
    int target = 1, ans = shortestSubarray(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 2 }, k = 4;
    int target = -1, ans = shortestSubarray(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 2, -1, 2 }, k = 3;
    int target = 3, ans = shortestSubarray(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int nums[] = { 84, -37, 32, 40, 95 }, k = 167;
    int target = 3, ans = shortestSubarray(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow) {
    int k = 1000000000, tmp = 100000, nums[tmp];
    for (int i = 0; i < tmp; nums[i++] = -tmp) {}
    int target = -1, ans = shortestSubarray(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_overflow);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}