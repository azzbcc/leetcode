/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/14 上午11:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0032.c"

START_TEST(test_official_1) {
    char *s = "(()";
    int target = 2, ans = longestValidParentheses(s);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *s = ")()())";
    int target = 4, ans = longestValidParentheses(s);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    char *s = "";
    int target = 0, ans = longestValidParentheses(s);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}