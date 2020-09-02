/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/2 上午11:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "offer_20.c"

START_TEST(test_true) {
    ck_assert_int_eq(true, isNumber("+100"));
    ck_assert_int_eq(true, isNumber("5e2"));
    ck_assert_int_eq(true, isNumber("-123"));
    ck_assert_int_eq(true, isNumber("3.1416"));
    ck_assert_int_eq(true, isNumber("-1E-16"));
    ck_assert_int_eq(true, isNumber("0123"));
}

START_TEST(test_false) {
    ck_assert_int_eq(false, isNumber("12e"));
    ck_assert_int_eq(false, isNumber("1a3.14"));
    ck_assert_int_eq(false, isNumber("1.2.3"));
    ck_assert_int_eq(false, isNumber("+-5"));
    ck_assert_int_eq(false, isNumber("12e+5.4"));
}

START_TEST(test_failed) {
    ck_assert_int_eq(true, isNumber(" 005047e+6"));
    ck_assert_int_eq(true, isNumber("46.e3"));
    ck_assert_int_eq(true, isNumber("3."));
    ck_assert_int_eq(false, isNumber("."));
    ck_assert_int_eq(true, isNumber(".1"));
    ck_assert_int_eq(true, isNumber("1 "));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_true);
    tcase_add_test(t, test_false);
}