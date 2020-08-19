/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/19 上午11:30
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdio.h>

#include "0647.c"

START_TEST(test_official_1) {
    char *input = "abc";
    int target = 3, ans = countSubstrings(input);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *input = "aaa";
    int target = 6, ans = countSubstrings(input);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}