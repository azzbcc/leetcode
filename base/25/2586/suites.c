/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/11/7 11:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2586.c"

START_TEST(test_official_1) {
    char *words[] = { "are", "amy", "u" };
    int left = 0, right = 2;
    int target = 2, ans = vowelStrings(words, LEN(words), left, right);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *words[] = { "hey", "aeo", "mu", "ooo", "artro" };
    int left = 1, right = 4;
    int target = 3, ans = vowelStrings(words, LEN(words), left, right);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}