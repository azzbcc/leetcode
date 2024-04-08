/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/8 14:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2009.c"

START_TEST(test_official_1) {
    int nums[] = { 4, 2, 5, 3 };
    int target = 0, ans = minOperations(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 2, 3, 5, 6 };
    int target = 1, ans = minOperations(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 1, 10, 100, 1000 };
    int target = 3, ans = minOperations(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_01) {
    int nums[] = { 8, 5, 9, 9, 8, 4 };
    int target = 2, ans = minOperations(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}
START_TEST(test_failed_02) {
    int nums[] = { 41, 33, 29, 33, 35, 26, 47, 24, 18, 28 };
    int target = 5, ans = minOperations(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_02);
    tcase_add_test(t, test_failed_01);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}