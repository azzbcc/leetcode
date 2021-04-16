/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/16 下午12:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0087.c"

START_TEST(test_official_1) {
    char *s1 = "great", *s2 = "rgeat";
    bool target = true, ans = isScramble(s1, s2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s1 = "abcde", *s2 = "caebd";
    bool target = false, ans = isScramble(s1, s2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s1 = "a", *s2 = "a";
    bool target = true, ans = isScramble(s1, s2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
    char *s1 = "eebaacbcbcadaaedceaaacadccd", *s2 = "eadcaacabaddaceacbceaabeccd";
    bool target = false, ans = isScramble(s1, s2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *s1 = "abcdbdacbdac", *s2 = "bdacabcdbdac";
    bool target = true, ans = isScramble(s1, s2);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);

    set_execute_timeout(t, 0.1);
}