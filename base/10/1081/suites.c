/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/12 下午3:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1081.c"

START_TEST(test_official_1) {
    char *s      = "bcabc";
    char *target = "abc", *ans = smallestSubsequence(s);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s      = "cbacdcbc";
    char *target = "acdb", *ans = smallestSubsequence(s);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}