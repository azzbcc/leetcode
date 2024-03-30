/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/30 12:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2952.c"

START_TEST(test_official_1) {
    int coins[] = { 1, 4, 10 }, k = 19;
    int target = 2, ans = minimumAddedCoins(coins, LEN(coins), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int coins[] = { 1, 4, 10, 5, 7, 19 }, k = 19;
    int target = 1, ans = minimumAddedCoins(coins, LEN(coins), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int coins[] = { 1, 1, 1 }, k = 20;
    int target = 3, ans = minimumAddedCoins(coins, LEN(coins), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}