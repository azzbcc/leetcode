/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/8 上午11:41
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1021.c"

START_TEST(test_official_1) {
    char *input = "(()())(())";
    char *target = "()()()", *ans = removeOuterParentheses(input);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_2) {
    char *input = "(()())(())(()(()))";
    char *target = "()()()()(())", *ans = removeOuterParentheses(input);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_3) {
    char *input = "()()";
    char *target = "", *ans = removeOuterParentheses(input);

    ck_assert_str_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}