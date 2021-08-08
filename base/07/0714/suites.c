/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/17 上午11:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0714.c"

START_TEST(test_official) {
    int prices[] = { 2, 1, 3, 2, 8, 4, 9, 9 }, fee = 2;

    int target = 8, ans = maxProfit(prices, LEN(prices), fee);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int prices[] = { 1181, 3699, 2571, 3082, 2223, 4929 }, fee = 1231;

    int target = 2762, ans = maxProfit(prices, LEN(prices), fee);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}