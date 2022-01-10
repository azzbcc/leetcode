/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/10 上午11:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0306.c"

START_TEST(test_official_1) {
    char *num   = "112358";
    bool target = true, ans = isAdditiveNumber(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *num   = "199100199";
    bool target = true, ans = isAdditiveNumber(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *num   = "99999999999999999099999999999999999";
    bool target = true, ans = isAdditiveNumber(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *num   = "0";
    bool target = false, ans = isAdditiveNumber(num);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}