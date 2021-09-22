/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/22 上午11:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1556.c"

START_TEST(test_official_1) {
    int n        = 987;
    char *target = "987";
    char *ans    = thousandSeparator(n);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int n        = 1234;
    char *target = "1.234";
    char *ans    = thousandSeparator(n);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int n        = 123456789;
    char *target = "123.456.789";
    char *ans    = thousandSeparator(n);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    int n        = 0;
    char *target = "0";
    char *ans    = thousandSeparator(n);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    int n        = 51040;
    char *target = "51.040";
    char *ans    = thousandSeparator(n);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_limit) {
    int n        = INT32_MAX;
    char *target = "2.147.483.647";
    char *ans    = thousandSeparator(n);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}