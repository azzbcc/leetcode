/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/5 00:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0309.c"

START_TEST(test_official_1) {
    int prices[] = { 1, 2, 3, 0, 2 };
    int target = 3, ans = maxProfit(prices, LEN(prices));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int prices[] = { 1 };
    int target = 0, ans = maxProfit(prices, LEN(prices));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}