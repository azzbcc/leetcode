/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/4 下午4:30
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdbool.h>

#include "0010.c"

START_TEST(test_official_1) {
    bool target = false, ans = isMatch("aa", "a");

    ck_assert_msg(target == ans, "error, except %d but got %d on isMatch().", target, ans);
}

START_TEST(test_official_2) {
    bool target = true, ans = isMatch("aa", "a*");

    ck_assert_msg(target == ans, "error, except %d but got %d on isMatch().", target, ans);
}

START_TEST(test_official_3) {
    bool target = true, ans = isMatch("ab", ".*");

    ck_assert_msg(target == ans, "error, except %d but got %d on isMatch().", target, ans);
}

START_TEST(test_official_4) {
    bool target = true, ans = isMatch("aab", "c*a*b");

    ck_assert_msg(target == ans, "error, except %d but got %d on isMatch().", target, ans);
}

START_TEST(test_official_5) {
    bool target = false, ans = isMatch("mississippi", "mis*is*p*.");

    ck_assert_msg(target == ans, "error, except %d but got %d on isMatch().", target, ans);
}

START_TEST(test_own) {
    bool target = true, ans = isMatch("abcdcc", "ab.*c*");

    ck_assert_msg(target == ans, "error, except %d but got %d on isMatch().", target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}