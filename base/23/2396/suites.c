/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/15 下午8:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2396.c"

START_TEST(test_official_1) {
    int n = 9;
    ck_assert_int_eq(false, isStrictlyPalindromic(n));
}

START_TEST(test_official_2) {
    int n = 4;
    ck_assert_int_eq(false, isStrictlyPalindromic(n));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}