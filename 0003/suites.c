/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/25 下午1:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdbool.h>

#include "0003.c"

START_TEST(test_official_01) {
    char *str = "abcabcbb";
    long target = 3, ans = lengthOfLongestSubstring(str);

    ck_assert_msg(ans == target, "error, except %ld but got %ld on lengthOfLongestSubstring('%s').", target, ans, str);
}

START_TEST(test_official_02) {
    char *str = "bbbbb";
    long target = 1, ans = lengthOfLongestSubstring(str);

    ck_assert_msg(ans == target, "error, except %ld but got %ld on lengthOfLongestSubstring('%s').", target, ans, str);
}

START_TEST(test_official_03) {
    char *str = "pwwkew";
    long target = 3, ans = lengthOfLongestSubstring(str);

    ck_assert_msg(ans == target, "error, except %ld but got %ld on lengthOfLongestSubstring('%s').", target, ans, str);
}

START_TEST(failed_01) {
    char *str = "ggububgvfk";
    long target = 6, ans = lengthOfLongestSubstring(str);

    ck_assert_msg(ans == target, "error, except %ld but got %ld on lengthOfLongestSubstring('%s').", target, ans, str);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_01);
    tcase_add_test(t, test_official_02);
    tcase_add_test(t, test_official_03);
    tcase_add_test(t, failed_01);
}