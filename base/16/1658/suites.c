/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/7 下午9:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1658.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 1, 4, 2, 3 }, x = 5;
    int target = 2, ans = minOperations(nums, LEN(nums), x);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 5, 6, 7, 8, 9 }, x = 4;
    int target = -1, ans = minOperations(nums, LEN(nums), x);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 3, 2, 20, 1, 1, 3 }, x = 10;
    int target = 5, ans = minOperations(nums, LEN(nums), x);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int nums[] = { 8828, 9581, 49, 9818, 9974, 9869, 9991, 10000, 10000, 10000, 9999, 9993, 9904, 8819, 1231, 6309 };
    int x = 134365, target = 16, ans = minOperations(nums, LEN(nums), x);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int nums[] = { 10, 10, 10, 10, 10 };
    int x = 100, target = -1, ans = minOperations(nums, LEN(nums), x);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}