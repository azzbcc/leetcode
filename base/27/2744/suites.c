/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/17 16:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2744.c"

START_TEST(test_official_1) {
    char *words[] = { "cd", "ac", "dc", "ca", "zz" };
    int target = 2, ans = maximumNumberOfStringPairs(words, LEN(words));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *words[] = { "ab", "ba", "cc" };
    int target = 1, ans = maximumNumberOfStringPairs(words, LEN(words));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *words[] = { "aa", "ab" };
    int target = 0, ans = maximumNumberOfStringPairs(words, LEN(words));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}