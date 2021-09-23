/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/3 下午5:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0008.c"

START_TEST(test_official_1) {
    char *input = "42";
    int target = 42, ans = myAtoi(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on reverse('%s').", target, ans, input);
}

START_TEST(test_official_2) {
    char *input = "   -42";
    int target = -42, ans = myAtoi(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on reverse('%s').", target, ans, input);
}

START_TEST(test_official_3) {
    char *input = "4193 with words";
    int target = 4193, ans = myAtoi(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on reverse('%s').", target, ans, input);
}

START_TEST(test_official_4) {
    char *input = "words and 987";
    int target = 0, ans = myAtoi(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on reverse('%s').", target, ans, input);
}

START_TEST(test_official_5) {
    char *input = "-91283472332";
    int target = -2147483648, ans = myAtoi(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on reverse('%s').", target, ans, input);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}