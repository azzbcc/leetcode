/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/30 上午11:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0343.c"

START_TEST(test_official_1) {
    int n = 2, target = 1;

    int ans = integerBreak(n);
    ck_assert_msg(ans == target, "error, except %d but got %d on integerBreak(%d).", target, ans, n);
}

START_TEST(test_official_2) {
    int n = 10, target = 36;

    int ans = integerBreak(n);
    ck_assert_msg(ans == target, "error, except %d but got %d on integerBreak(%d).", target, ans, n);
}

START_TEST(test_own) {
    int n = 58, target = 1549681956;

    int ans = integerBreak(n);
    ck_assert_msg(ans == target, "error, except %d but got %d on integerBreak(%d).", target, ans, n);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}