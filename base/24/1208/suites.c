/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/5 上午4:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1208.c"

START_TEST(test_official_1) {
    char *s = "abcd", *t = "bcdf";
    int target = 3, ans = equalSubstring(s, t, 3);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "abcd", *t = "cdef";
    int target = 1, ans = equalSubstring(s, t, 3);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s = "abcd", *t = "acde";
    int target = 1, ans = equalSubstring(s, t, 0);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}