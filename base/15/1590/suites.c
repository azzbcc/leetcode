/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/10 上午10:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1590.c"

START_TEST(test_official_1) {
    int nums[] = { 3, 1, 4, 2 }, p = 6;
    int target = 1, ans = minSubarray(nums, LEN(nums), p);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 6, 3, 5, 2 }, p = 9;
    int target = 2, ans = minSubarray(nums, LEN(nums), p);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 1, 2, 3 }, p = 3;
    int target = 0, ans = minSubarray(nums, LEN(nums), p);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int nums[] = { 1, 2, 3 }, p = 7;
    int target = -1, ans = minSubarray(nums, LEN(nums), p);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int nums[] = { 1000000000, 1000000000, 1000000000 }, p = 3;
    int target = 0, ans = minSubarray(nums, LEN(nums), p);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}