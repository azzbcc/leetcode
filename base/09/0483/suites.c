/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/18 下午12:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0483.c"

START_TEST(test_official_1) {
    char *n      = "13";
    char *target = "3", *ans = smallestGoodBase(n);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *n      = "4681";
    char *target = "8", *ans = smallestGoodBase(n);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char *n      = "1000000000000000000";
    char *target = "999999999999999999", *ans = smallestGoodBase(n);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    char *n      = "15";
    char *target = "2", *ans = smallestGoodBase(n);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}