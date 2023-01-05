/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/5 下午7:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1803.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 4, 2, 7 }, low = 2, high = 6;
    int target = 6, ans = countPairs(nums, LEN(nums), low, high);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 9, 8, 4, 2, 1 }, low = 5, high = 14;
    int target = 8, ans = countPairs(nums, LEN(nums), low, high);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}