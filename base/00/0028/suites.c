/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/14 下午3:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdbool.h>

#include "0029.c"

START_TEST(test_official_1) {
    char *haystack = "hello", *needle = "ll";
    int target = 2, ans = strStr(haystack, needle);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *haystack = "aaaaa", *needle = "bba";
    int target = -1, ans = strStr(haystack, needle);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}