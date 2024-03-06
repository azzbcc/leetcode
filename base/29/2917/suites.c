/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/6 14:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include "common.h"

#include "2917.c"

START_TEST(test_official_1) {
    int nums[] = { 7, 12, 9, 8, 9, 15 }, k = 4;
    int target = 9, ans = findKOr(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 2, 12, 1, 11, 4, 5 }, k = 6;
    int target = 0, ans = findKOr(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 10, 8, 5, 9, 11, 6, 8 }, k = 1;
    int target = 15, ans = findKOr(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}