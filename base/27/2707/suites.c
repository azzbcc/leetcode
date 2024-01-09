/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/9 14:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2707.c"

START_TEST(test_official_1) {
    char *s = "leetscode", *dictionary[] = { "leet", "code", "leetcode" };
    int target = 1, ans = minExtraChar(s, dictionary, LEN(dictionary));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "sayhelloworld", *dictionary[] = { "hello", "world" };
    int target = 3, ans = minExtraChar(s, dictionary, LEN(dictionary));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}