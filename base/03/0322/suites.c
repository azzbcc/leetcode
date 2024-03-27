/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/27 15:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0322.c"

START_TEST(test_official_1) {
    int coins[] = { 1, 2, 5 }, amount = 11;
    int target = 3, ans = coinChange(coins, LEN(coins), amount);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int coins[] = { 2 }, amount = 3;
    int target = -1, ans = coinChange(coins, LEN(coins), amount);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int coins[] = { 1 }, amount = 0;
    int target = 0, ans = coinChange(coins, LEN(coins), amount);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow) {
    int coins[] = { 1, 2147483647 }, amount = 2;
    int target = 2, ans = coinChange(coins, LEN(coins), amount);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_overflow);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}