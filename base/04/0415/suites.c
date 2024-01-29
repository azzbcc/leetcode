/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/3 上午10:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */

#include <common.h>

#include "0415.c"

START_TEST(test_own) {
    char *num1 = "987654321", *num2 = "12345689";
    char *target = "1000000010", *ans = addStrings(num1, num2);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_1) {
    char *num1 = "11", *num2 = "123";
    char *target = "134", *ans = addStrings(num1, num2);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *num1 = "456", *num2 = "77";
    char *target = "533", *ans = addStrings(num1, num2);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char *num1 = "0", *num2 = "0";
    char *target = "0", *ans = addStrings(num1, num2);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}