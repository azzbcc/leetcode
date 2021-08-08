/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/26 下午4:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1190.c"

START_TEST(test_official_1) {
    char *s      = "(abcd)";
    char *target = "dcba";
    char *ans    = reverseParentheses(s);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s      = "(u(love)i)";
    char *target = "iloveu";
    char *ans    = reverseParentheses(s);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s      = "(ed(et(oc))el)";
    char *target = "leetcode";
    char *ans    = reverseParentheses(s);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    char *s      = "a(bcdefghijkl(mno)p)q";
    char *target = "apmnolkjihgfedcbq";
    char *ans    = reverseParentheses(s);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}