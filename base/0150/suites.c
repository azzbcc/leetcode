/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/25 下午6:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0150.c"

START_TEST(test_official_1) {
    char* words[] = { "2", "1", "+", "3", "*" };

    int target = 9, ans = evalRPN(words, sizeof(words) / sizeof(words[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char* words[] = { "4", "13", "5", "/", "+" };

    int target = 6, ans = evalRPN(words, sizeof(words) / sizeof(words[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    char* words[] = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };

    int target = 22, ans = evalRPN(words, sizeof(words) / sizeof(words[0]));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase* t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}