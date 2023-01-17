/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/17 下午4:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1814.c"

START_TEST(test_official_1) {
    int nums[] = { 42, 11, 1, 97 };
    int target = 2, ans = countNicePairs(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 13, 10, 35, 24, 76 };
    int target = 4, ans = countNicePairs(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}