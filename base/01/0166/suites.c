/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/3 上午1:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0166.c"

START_TEST(test_official_1) {
    int numerator = 1, denominator = 2;
    char *target = "0.5", *ans = fractionToDecimal(numerator, denominator);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int numerator = 2, denominator = 1;
    char *target = "2", *ans = fractionToDecimal(numerator, denominator);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int numerator = 2, denominator = 3;
    char *target = "0.(6)", *ans = fractionToDecimal(numerator, denominator);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    int numerator = 4, denominator = 333;
    char *target = "0.(012)", *ans = fractionToDecimal(numerator, denominator);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_5) {
    int numerator = 1, denominator = 5;
    char *target = "0.2", *ans = fractionToDecimal(numerator, denominator);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_own) {
    int numerator = 1, denominator = 6;
    char *target = "0.1(6)", *ans = fractionToDecimal(numerator, denominator);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_1) {
    int numerator = -50, denominator = 8;
    char *target = "-6.25", *ans = fractionToDecimal(numerator, denominator);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_2) {
    int numerator = 7, denominator = -12;
    char *target = "-0.58(3)", *ans = fractionToDecimal(numerator, denominator);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_limit_1) {
    int numerator = -1, denominator = INT32_MIN;
    char *target = "0.0000000004656612873077392578125", *ans = fractionToDecimal(numerator, denominator);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_limit_2) {
    int numerator = INT32_MIN, denominator = 1;
    char *target = "-2147483648", *ans = fractionToDecimal(numerator, denominator);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit_2);
    tcase_add_test(t, test_limit_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}