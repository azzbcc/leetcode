/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/29 下午12:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0214.c"

START_TEST(test_official_1) {
    char *input  = "aacecaaa";
    char *target = "aaacecaaa", *ans = shortestPalindrome(input);

    ck_assert_str_eq(target, ans);

    free(ans);
}

START_TEST(test_official_2) {
    char *input  = "abcd";
    char *target = "dcbabcd", *ans = shortestPalindrome(input);

    ck_assert_str_eq(target, ans);

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}
