/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/31 下午2:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0507.c"

START_TEST(test_official_1) {
    int num     = 28;
    bool target = true, ans = checkPerfectNumber(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int num     = 6;
    bool target = true, ans = checkPerfectNumber(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int num     = 496;
    bool target = true, ans = checkPerfectNumber(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int num     = 8128;
    bool target = true, ans = checkPerfectNumber(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int num     = 2;
    bool target = false, ans = checkPerfectNumber(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int num     = 1;
    bool target = false, ans = checkPerfectNumber(num);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}