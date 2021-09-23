/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/5 上午13:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0013.c"

START_TEST(test_official_1) {
    char *input = "III";
    int target = 3, ans = romanToInt(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on romanToInt(%s).", target, ans, input);
}

START_TEST(test_official_2) {
    char *input = "IV";
    int target = 4, ans = romanToInt(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on romanToInt(%s).", target, ans, input);
}

START_TEST(test_official_3) {
    char *input = "IX";
    int target = 9, ans = romanToInt(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on romanToInt(%s).", target, ans, input);
}

START_TEST(test_official_4) {
    char *input = "LVIII";
    int target = 58, ans = romanToInt(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on romanToInt(%s).", target, ans, input);
}

START_TEST(test_official_5) {
    char *input = "MCMXCIV";
    int target = 1994, ans = romanToInt(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on romanToInt(%s).", target, ans, input);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}