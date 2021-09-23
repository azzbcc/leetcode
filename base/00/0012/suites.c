/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/5 上午13:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0012.c"

START_TEST(test_official_1) {
    int input = 3;
    char *target = "III", *ans = intToRoman(input);
    ck_assert_msg(!strcmp(target, ans), "error, except %s but got %s on intToRoman(%d).", target, ans, input);
}

START_TEST(test_official_2) {
    int input = 4;
    char *target = "IV", *ans = intToRoman(input);
    ck_assert_msg(!strcmp(target, ans), "error, except %s but got %s on intToRoman(%d).", target, ans, input);
}

START_TEST(test_official_3) {
    int input = 9;
    char *target = "IX", *ans = intToRoman(input);
    ck_assert_msg(!strcmp(target, ans), "error, except %s but got %s on intToRoman(%d).", target, ans, input);
}

START_TEST(test_official_4) {
    int input = 58;
    char *target = "LVIII", *ans = intToRoman(input);
    ck_assert_msg(!strcmp(target, ans), "error, except %s but got %s on intToRoman(%d).", target, ans, input);
}

START_TEST(test_official_5) {
    int input = 1994;
    char *target = "MCMXCIV", *ans = intToRoman(input);
    ck_assert_msg(!strcmp(target, ans), "error, except %s but got %s on intToRoman(%d).", target, ans, input);
}

START_TEST(test_own) {
    int input = 3888;
    char *target = "MMMDCCCLXXXVIII", *ans = intToRoman(input);
    ck_assert_msg(!strcmp(target, ans), "error, except %s but got %s on intToRoman(%d).", target, ans, input);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}