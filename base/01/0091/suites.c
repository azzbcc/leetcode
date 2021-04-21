/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/21 下午12:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0091.c"

START_TEST(test_official_1) {
    char *s    = "12";
    int target = 2, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = "226";
    int target = 3, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s    = "0";
    int target = 0, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *s    = "06";
    int target = 0, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *s    = "120012";
    int target = 0, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}