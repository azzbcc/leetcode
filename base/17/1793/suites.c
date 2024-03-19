/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/19 15:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1793.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 4, 3, 7, 4, 5 }, k = 3;
    int target = 15, ans = maximumScore(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 5, 5, 4, 5, 4, 1, 1, 1 }, k = 0;
    int target = 20, ans = maximumScore(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}