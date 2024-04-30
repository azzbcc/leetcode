/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/30 08:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2798.c"

START_TEST(test_official_1) {
    int hours[] = { 0, 1, 2, 3, 4 }, t = 2;
    int target = 3, ans = numberOfEmployeesWhoMetTarget(hours, LEN(hours), t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int hours[] = { 5, 1, 4, 2, 2 }, t = 6;
    int target = 0, ans = numberOfEmployeesWhoMetTarget(hours, LEN(hours), t);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}