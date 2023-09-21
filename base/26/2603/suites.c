/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/21 10:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2603.c"

START_TEST(test_official_1) {
    int coins[]  = { 1, 0, 0, 0, 0, 1 };
    int *edges[] = { (int[]) { 0, 1 }, (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 3, 4 }, (int[]) { 4, 5 } };

    int target = 2, ans = collectTheCoins(coins, LEN(coins), edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int coins[]  = { 0, 0, 0, 1, 1, 0, 0, 1 };
    int *edges[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 1, 3 }, (int[]) { 1, 4 },
                     (int[]) { 2, 5 }, (int[]) { 5, 6 }, (int[]) { 5, 7 } };

    int target = 2, ans = collectTheCoins(coins, LEN(coins), edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int coins[]  = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int *edges[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 1, 3 }, (int[]) { 1, 4 },
                     (int[]) { 2, 5 }, (int[]) { 5, 6 }, (int[]) { 5, 7 } };

    int target = 0, ans = collectTheCoins(coins, LEN(coins), edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}