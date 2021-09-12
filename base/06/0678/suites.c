/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/12 下午3:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0678.c"

START_TEST(test_official_1) {
    char *s     = "()";
    bool target = true, ans = checkValidString(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s     = "(*)";
    bool target = true, ans = checkValidString(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s     = "(*))";
    bool target = true, ans = checkValidString(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    char *s     = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()";
    bool target = true, ans = checkValidString(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    char *s     = "(((((()*)(*)*))())())(()())())))((**)))))(()())()";
    bool target = false, ans = checkValidString(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_3) {
    char *s     = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    bool target = false, ans = checkValidString(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}