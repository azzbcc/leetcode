/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/29 上午10:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0168.c"

START_TEST(test_official_1) {
    int num      = 1;
    char *target = "A", *ans = convertToTitle(num);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int num      = 28;
    char *target = "AB", *ans = convertToTitle(num);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int num      = 701;
    char *target = "ZY", *ans = convertToTitle(num);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}