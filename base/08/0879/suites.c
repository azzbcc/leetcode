/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/9 下午1:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0879.c"

START_TEST(test_official_1) {
    int n = 5, minProfit = 3, group[] = { 2, 2 }, profit[] = { 2, 3 };
    int target = 2, ans = profitableSchemes(n, minProfit, group, LEN(group), profit, LEN(profit));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 10, minProfit = 5, group[] = { 2, 3, 5 }, profit[] = { 6, 7, 8 };
    int target = 7, ans = profitableSchemes(n, minProfit, group, LEN(group), profit, LEN(profit));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}