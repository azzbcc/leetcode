/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/26 下午7:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0640.c"

START_TEST(test_official_1) {
    char *equation = "x+5-3+x=6+x-2";
    char *target = "x=2", *ans = solveEquation(equation);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *equation = "x=x";
    char *target = "Infinite solutions", *ans = solveEquation(equation);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char *equation = "2x=x";
    char *target = "x=0", *ans = solveEquation(equation);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    char *equation = "2x+3x-6x=x+2";
    char *target = "x=-1", *ans = solveEquation(equation);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_5) {
    char *equation = "x=x+2";
    char *target = "No solution", *ans = solveEquation(equation);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    char *equation = "0x=0";
    char *target = "Infinite solutions", *ans = solveEquation(equation);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}