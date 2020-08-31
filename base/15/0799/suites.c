/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/31 下午4:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0799.c"

START_TEST(test_official_1) {
    double target = 0, ans = champagneTower(1, 1, 1);

    ck_assert_double_eq(target, ans);
}

START_TEST(test_official_2) {
    double target = 0.5, ans = champagneTower(2, 1, 1);

    ck_assert_double_eq(target, ans);
}

START_TEST(test_own) {
    double target = 1, ans = champagneTower(1250, 16, 8);

    ck_assert_double_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}