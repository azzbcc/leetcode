/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/29 15:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2908.c"

START_TEST(test_official_1) {
    int nums[] = { 8, 6, 1, 5, 3 };
    int target = 9, ans = minimumSum(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 5, 4, 8, 7, 10, 2 };
    int target = 13, ans = minimumSum(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 6, 5, 4, 3, 4, 5 };
    int target = -1, ans = minimumSum(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int nums[] = { 1, 2, 1, 2 };
    int target = 4, ans = minimumSum(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}