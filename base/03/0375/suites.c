/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/12 上午11:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0375.c"

START_TEST(test_official_1) {
    int n      = 10;
    int target = 16, ans = getMoneyAmount(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 1;
    int target = 0, ans = getMoneyAmount(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n      = 2;
    int target = 1, ans = getMoneyAmount(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_max) {
    int n      = 200;
    int target = 952, ans = getMoneyAmount(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_max);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}