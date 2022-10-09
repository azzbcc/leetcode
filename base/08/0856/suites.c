/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/9 下午2:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0856.c"

START_TEST(test_official_1) {
    char *s    = "()";
    int target = 1, ans = scoreOfParentheses(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = "(())";
    int target = 2, ans = scoreOfParentheses(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s    = "()()";
    int target = 2, ans = scoreOfParentheses(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *s    = "(()(()))";
    int target = 6, ans = scoreOfParentheses(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}