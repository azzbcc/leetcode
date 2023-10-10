/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/10 14:28
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2731.c"

START_TEST(test_official_1) {
    char *s = "RLL";
    int d = 3, nums[] = { -2, 0, 2 };
    int target = 8, ans = sumDistance(nums, LEN(nums), s, d);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "RL";
    int d = 2, nums[] = { 1, 0 };
    int target = 5, ans = sumDistance(nums, LEN(nums), s, d);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *s = "LLLLL";
    int d = 10, nums[] = { 0, 2, 7, 5, 1 };
    int target = 36, ans = sumDistance(nums, LEN(nums), s, d);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *s = "LRLLR";
    int d = 2, nums[] = { -10, -13, 10, 14, 11 };

    int target = 146, ans = sumDistance(nums, LEN(nums), s, d);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}