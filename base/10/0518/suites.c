/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/10 上午10:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0518.c"

START_TEST(test_official_1) {
    int amount = 5, coins[] = { 1, 2, 5 };
    int target = 4, ans = change(amount, coins, LEN(coins));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int amount = 3, coins[] = { 2 };
    int target = 0, ans = change(amount, coins, LEN(coins));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int amount = 10, coins[] = { 10 };
    int target = 1, ans = change(amount, coins, LEN(coins));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}