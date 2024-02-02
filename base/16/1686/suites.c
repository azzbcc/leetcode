/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/2 20:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1686.c"

START_TEST(test_official_1) {
    int aliceValues[] = { 1, 3 }, bobValues[] = { 2, 1 };
    int target = 1, ans = stoneGameVI(aliceValues, LEN(aliceValues), bobValues, LEN(bobValues));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int aliceValues[] = { 1, 2 }, bobValues[] = { 3, 1 };
    int target = 0, ans = stoneGameVI(aliceValues, LEN(aliceValues), bobValues, LEN(bobValues));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int aliceValues[] = { 2, 4, 3 }, bobValues[] = { 1, 6, 7 };
    int target = -1, ans = stoneGameVI(aliceValues, LEN(aliceValues), bobValues, LEN(bobValues));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}