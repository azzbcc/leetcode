/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/18 上午10:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0476.c"

START_TEST(test_official_1) {
    int n      = 5;
    int target = 2, ans = findComplement(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 1;
    int target = 0, ans = findComplement(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_limit) {
    int n      = INT32_MAX;
    int target = 0, ans = findComplement(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int n      = INT32_MAX - 1;
    int target = 1, ans = findComplement(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}