/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/14 上午10:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0524.c"

START_TEST(test_official_1) {
    char *s = "abpcplea", *dictionary[] = { "ale", "apple", "monkey", "plea" };
    char *target = "apple", *ans = findLongestWord(s, dictionary, LEN(dictionary));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "abpcplea", *dictionary[] = { "a", "b", "c" };
    char *target = "a", *ans = findLongestWord(s, dictionary, LEN(dictionary));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_1) {
    char *s = "aaa", *dictionary[] = { "aaa", "aa", "a" };
    char *target = "aaa", *ans = findLongestWord(s, dictionary, LEN(dictionary));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_2) {
    char *s = "abce", *dictionary[] = { "abe", "abc" };
    char *target = "abc", *ans = findLongestWord(s, dictionary, LEN(dictionary));
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}