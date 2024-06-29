/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/6/29 18:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2734.c"

START_TEST(test_official_1) {
    char s[]     = "cbabc";
    char *target = "baabc", *ans = smallestString(s);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char s[]     = "acbbc";
    char *target = "abaab", *ans = smallestString(s);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char s[]     = "leetcode";
    char *target = "kddsbncd", *ans = smallestString(s);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    char s[]     = "aa";
    char *target = "az", *ans = smallestString(s);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    char s[]     = "ba";
    char *target = "aa", *ans = smallestString(s);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}