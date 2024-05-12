/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/5/12 18:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1553.c"

START_TEST(test_official_1) {
    int target = 4, ans = minDays(10);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int target = 3, ans = minDays(6);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int target = 1, ans = minDays(1);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int target = 6, ans = minDays(56);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int target = 35, ans = minDays(INT32_MAX);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}