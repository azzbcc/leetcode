/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/1 00:22
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0121.c"

START_TEST(test_official_1) {
    int prices[] = { 7, 1, 5, 3, 6, 4 };
    int target = 5, ans = maxProfit(prices, LEN(prices));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int prices[] = { 7, 6, 4, 3, 1 };
    int target = 0, ans = maxProfit(prices, LEN(prices));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}