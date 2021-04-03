/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/3 下午12:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1143.c"

START_TEST(test_official_1) {
    char *text1 = "abcde", *text2 = "ace";
    int target = 3, ans = longestCommonSubsequence(text1, text2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *text1 = "abc", *text2 = "abc";
    int target = 3, ans = longestCommonSubsequence(text1, text2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *text1 = "abc", *text2 = "def";
    int target = 0, ans = longestCommonSubsequence(text1, text2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *text1 = "ezupkr", *text2 = "ubmrapg";
    int target = 2, ans = longestCommonSubsequence(text1, text2);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}