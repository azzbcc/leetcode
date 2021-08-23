/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/23 上午11:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1646.c"

START_TEST(test_official_1) {
    int n      = 7;
    int target = 3, ans = getMaximumGenerated(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 2;
    int target = 1, ans = getMaximumGenerated(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n      = 3;
    int target = 2, ans = getMaximumGenerated(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int n      = 4;
    int target = 2, ans = getMaximumGenerated(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}