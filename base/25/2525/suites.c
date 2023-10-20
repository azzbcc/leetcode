/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/20 14:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2525.c"

START_TEST(test_official_1) {
    int length = 1000, width = 35, height = 700, mass = 300;
    char *target = "Heavy", *ans = categorizeBox(length, width, height, mass);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int length = 200, width = 50, height = 800, mass = 50;
    char *target = "Neither", *ans = categorizeBox(length, width, height, mass);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    int length = 50, width = 85, height = 191, mass = 136;
    char *target = "Heavy", *ans = categorizeBox(length, width, height, mass);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}