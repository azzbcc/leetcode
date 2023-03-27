/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/27 下午12:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1638.c"

START_TEST(test_official_1) {
    char *s = "aba", *t = "baba";
    int target = 6, ans = countSubstrings(s, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "ab", *t = "bb";
    int target = 3, ans = countSubstrings(s, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s = "a", *t = "a";
    int target = 0, ans = countSubstrings(s, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *s = "abe", *t = "bbc";
    int target = 10, ans = countSubstrings(s, t);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}