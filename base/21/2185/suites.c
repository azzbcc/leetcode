/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/8 下午1:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2185.c"

START_TEST(test_official_1) {
    char *words[] = { "pay", "attention", "practice", "attend" }, *pref = "at";
    int target = 2, ans = prefixCount(words, LEN(words), pref);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *words[] = { "leetcode", "win", "loops", "success" }, *pref = "code";
    int target = 0, ans = prefixCount(words, LEN(words), pref);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}