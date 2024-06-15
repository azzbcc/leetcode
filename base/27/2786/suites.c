/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/6/14 20:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2786.c"

START_TEST(test_officiai_1) {
    int nums[] = { 2, 3, 6, 1, 9, 2 }, x = 5;
    long long target = 13, ans = maxScore(nums, LEN(nums), x);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_officiai_2) {
    int nums[] = { 2, 4, 6, 8 }, x = 3;
    long long target = 20, ans = maxScore(nums, LEN(nums), x);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int x = 101278;
#include "failed.c"
    long long target = 20455698000, ans = maxScore(nums, LEN(nums), x);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_officiai_1);
    tcase_add_test(t, test_officiai_2);
}