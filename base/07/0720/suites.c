/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/17 上午10:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0720.c"

START_TEST(test_official_1) {
    char *words[] = { "w", "wo", "wor", "worl", "world" };
    char *target = "world", *ans = longestWord(words, LEN(words));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *words[] = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    char *target = "apple", *ans = longestWord(words, LEN(words));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    char *words[] = { "wo", "wor", "worl", "world" };
    char *target = "", *ans = longestWord(words, LEN(words));
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}