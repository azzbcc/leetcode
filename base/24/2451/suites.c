/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/25 00:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2451.c"

START_TEST(test_official_1) {
    char *words[] = { "adc", "wzy", "abc" };
    char *target = "abc", *ans = oddString(words, LEN(words));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *words[] = { "aaa", "bob", "ccc", "ddd" };
    char *target = "bob", *ans = oddString(words, LEN(words));
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}