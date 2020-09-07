/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/7 下午5:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0504.c"

START_TEST(test_official_1) {
    char *target = "202", *ans = convertToBase7(100);
    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_2) {
    char *target = "-10", *ans = convertToBase7(-7);
    ck_assert_str_eq(target, ans);
}

START_TEST(test_zero) {
    char *target = "0", *ans = convertToBase7(0);
    ck_assert_str_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_zero);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}