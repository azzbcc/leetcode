/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/31 下午1:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2367.c"

START_TEST(test_official_1) {
    int nums[] = { 0, 1, 4, 6, 7, 10 }, diff = 3;
    int target = 2, ans = arithmeticTriplets(nums, LEN(nums), diff);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 4, 5, 6, 7, 8, 9 }, diff = 2;
    int target = 2, ans = arithmeticTriplets(nums, LEN(nums), diff);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}