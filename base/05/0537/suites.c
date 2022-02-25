/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/25 上午10:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0537.c"

START_TEST(test_official_1) {
    char *num1 = "1+1i", *num2 = "1+1i";
    char *target = "0+2i", *ans = complexNumberMultiply(num1, num2);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *num1 = "1+-1i", *num2 = "1+-1i";
    char *target = "0+-2i", *ans = complexNumberMultiply(num1, num2);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    char *num1 = "78+-76i", *num2 = "-86+72i";
    char *target = "-1236+12152i", *ans = complexNumberMultiply(num1, num2);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}