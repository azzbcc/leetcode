/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/13 上午11:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0043.c"

START_TEST(test_official_1) {
    char *input_a = "2", *input_b = "3";
    char *target = "6", *ans = multiply(input_a, input_b);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_2) {
    char *input_a = "123", *input_b = "456";
    char *target = "56088", *ans = multiply(input_a, input_b);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_limit) {
    char *input_a = "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
                    "999999999999";
    char *input_b = "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
                    "999999999999";
    char *target = "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
                   "999999999980000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
                   "0000000000000000000001";
    char *ans = multiply(input_a, input_b);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_failed_1) {
    char *input_a = "0", *input_b = "0";
    char *target = "0", *ans = multiply(input_a, input_b);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_failed_2) {
    char *input_a = "6", *input_b = "501";
    char *target = "3006", *ans = multiply(input_a, input_b);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_failed_3) {
    char *input_a = "9133", *input_b = "0";
    char *target = "0", *ans = multiply(input_a, input_b);

    ck_assert_str_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}