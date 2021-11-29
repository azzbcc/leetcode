/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/29 上午10:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0438.c"

START_TEST(test_official_1) {
    char *s = "cbaebabacd", *p = "abc";
    int target[] = { 0, 6 };
    int len, *ans = findAnagrams(s, p, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    char *s = "abab", *p = "ab";
    int target[] = { 0, 1, 2 };
    int len, *ans = findAnagrams(s, p, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_failed_1) {
    char *s = "baa", *p = "aa";
    int target[] = { 1 };
    int len, *ans = findAnagrams(s, p, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_failed_2) {
    char *s = "aaaaaaaaaa", *p = "aaaaaaaaaaaaa";
    int target[] = {};
    int len, *ans = findAnagrams(s, p, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}