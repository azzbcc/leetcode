/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/7 上午9:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0875.c"

START_TEST(test_official_1) {
    int piles[] = { 3, 6, 7, 11 }, h = 8;
    int target = 4, ans = minEatingSpeed(piles, LEN(piles), h);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int piles[] = { 30, 11, 23, 4, 20 }, h = 5;
    int target = 30, ans = minEatingSpeed(piles, LEN(piles), h);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int piles[] = { 30, 11, 23, 4, 20 }, h = 6;
    int target = 23, ans = minEatingSpeed(piles, LEN(piles), h);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int piles[] = { 312884470 }, h = 968709470;
    int target = 1, ans = minEatingSpeed(piles, LEN(piles), h);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}