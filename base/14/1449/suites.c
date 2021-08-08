/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/12 下午9:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1449.c"

START_TEST(test_official_1) {
    int cost[] = { 4, 3, 2, 5, 6, 7, 2, 5, 5 }, k = 9;
    char *target = "7772", *ans = largestNumber(cost, LEN(cost), k);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int cost[] = { 7, 6, 5, 5, 5, 6, 8, 7, 8 }, k = 12;
    char *target = "85", *ans = largestNumber(cost, LEN(cost), k);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int cost[] = { 2, 4, 6, 2, 4, 6, 4, 4, 4 }, k = 5;
    char *target = "0", *ans = largestNumber(cost, LEN(cost), k);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    int cost[] = { 6, 10, 15, 40, 40, 40, 40, 40, 40 }, k = 47;
    char *target = "32211", *ans = largestNumber(cost, LEN(cost), k);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}