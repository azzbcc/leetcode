/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/17 上午10:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1518.c"

START_TEST(test_official_1) {
    int numBottles = 9, numExchange = 3;
    int target = 13, ans = numWaterBottles(numBottles, numExchange);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int numBottles = 15, numExchange = 4;
    int target = 19, ans = numWaterBottles(numBottles, numExchange);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int numBottles = 5, numExchange = 5;
    int target = 6, ans = numWaterBottles(numBottles, numExchange);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int numBottles = 2, numExchange = 3;
    int target = 2, ans = numWaterBottles(numBottles, numExchange);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}