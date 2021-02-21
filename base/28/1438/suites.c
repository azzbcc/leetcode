/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/21 上午12:42
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1438.c"

START_TEST(test_official_1) {
    int nums[] = { 8, 2, 4, 7 }, limit = 4;
    int target = 2, ans = longestSubarray(nums, LEN(nums), limit);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 10, 1, 2, 4, 7, 2 }, limit = 5;
    int target = 4, ans = longestSubarray(nums, LEN(nums), limit);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 4, 2, 2, 2, 4, 4, 2, 2 }, limit = 0;
    int target = 3, ans = longestSubarray(nums, LEN(nums), limit);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int nums[] = { 4, 8, 5, 1, 7, 9 }, limit = 6;
    int target = 3, ans = longestSubarray(nums, LEN(nums), limit);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}