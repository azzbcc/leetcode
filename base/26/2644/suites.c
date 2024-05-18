/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/5/18 16:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2644.c"

START_TEST(test_official_1) {
    int nums[] = { 4, 7, 9, 3, 9 }, divisors[] = { 5, 2, 3 };
    int target = 3, ans = maxDivScore(nums, LEN(nums), divisors, LEN(divisors));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 20, 14, 21, 10 }, divisors[] = { 5, 7, 5 };
    int target = 5, ans = maxDivScore(nums, LEN(nums), divisors, LEN(divisors));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 12 }, divisors[] = { 10, 16 };
    int target = 10, ans = maxDivScore(nums, LEN(nums), divisors, LEN(divisors));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}