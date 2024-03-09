/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/9 20:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2386.c"

START_TEST(test_official_1) {
    int nums[] = { 2, 4, -2 }, k = 5;
    long long target = 2, ans = kSum(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, -2, 3, 4, -10, 12 }, k = 16;
    long long target = 10, ans = kSum(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int nums[] = { -530219056, 353285209, 493533664 }, k = 6;
    long long target = -36685392, ans = kSum(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int nums[] = { -1, 1 }, k = 1;
    long long target = 1, ans = kSum(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}