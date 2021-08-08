/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/10 下午1:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0224.c"

START_TEST(test_official_1) {
    char *s    = "1 + 1";
    int target = 2, ans = calculate(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = " 2-1 + 2 ";
    int target = 3, ans = calculate(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s    = "(1+(4+5+2)-3)+(6+8)";
    int target = 23, ans = calculate(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_fail_1) {
    char *s    = "1-(5)";
    int target = -4, ans = calculate(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_fail_2) {
    char *s    = "-2+ 1";
    int target = -1, ans = calculate(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_fail_1);
    tcase_add_test(t, test_fail_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}