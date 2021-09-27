/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/27 上午10:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0639.c"

START_TEST(test_official_1) {
    char *s    = "*";
    int target = 9, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = "1*";
    int target = 18, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s    = "2*";
    int target = 15, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *s    = "11106";
    int target = 2, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    char *s    = "**";
    int target = 96, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    char *s    = "***";
    int target = 999, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_3) {
    char *s    = "*1*";
    int target = 180, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_4) {
    char *s    = "2839";
    int target = 1, ans = numDecodings(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_4);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}