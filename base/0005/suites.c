/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/31 下午3:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdbool.h>
#include <stdlib.h>

#include "0005.c"

START_TEST(test_official_1) {
    char *input = "babad";
    char *target = "bab", *ans = longestPalindrome(input);

    ck_assert_msg(0 == strcmp(target, ans), "error, except %s but got %s on longestPalindrome().", target, ans);

    free(ans);
}

START_TEST(test_official_2) {
    char *input = "cbbd";
    char *target = "bb", *ans = longestPalindrome(input);

    ck_assert_msg(0 == strcmp(target, ans), "error, except %s but got %s on longestPalindrome().", target, ans);

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}