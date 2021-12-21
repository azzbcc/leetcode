/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/21 上午11:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1154.c"

START_TEST(test_official_1) {
    char *date = "2019-01-09";
    int target = 9, ans = dayOfYear(date);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *date = "2019-02-10";
    int target = 41, ans = dayOfYear(date);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *date = "2003-03-01";
    int target = 60, ans = dayOfYear(date);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *date = "2004-03-01";
    int target = 61, ans = dayOfYear(date);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}