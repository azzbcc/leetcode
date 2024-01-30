/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/30 12:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2808.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 2, 1, 2 };
    int target = 1, ans = minimumSeconds(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 2, 1, 3, 3, 2 };
    int target = 2, ans = minimumSeconds(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 5, 5, 5, 5 };
    int target = 0, ans = minimumSeconds(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}