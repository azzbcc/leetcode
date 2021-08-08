/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/18 上午11:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0134.c"

START_TEST(test_official_1) {
    int gas[] = { 1, 2, 3, 4, 5 }, cost[] = { 3, 4, 5, 1, 2 };

    int target = 3, ans = canCompleteCircuit(gas, LEN(gas), cost, LEN(cost));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int gas[] = { 2, 3, 4 }, cost[] = { 3, 4, 3 };

    int target = -1, ans = canCompleteCircuit(gas, LEN(gas), cost, LEN(cost));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int gas[] = { 3, 1, 1 }, cost[] = { 1, 2, 2 };

    int target = 0, ans = canCompleteCircuit(gas, LEN(gas), cost, LEN(cost));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}