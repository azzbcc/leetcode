/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/1 上午11:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1662.c"

START_TEST(test_official_1) {
    char *word1[] = { "ab", "c" }, *word2[] = { "a", "bc" };
    ck_assert_int_eq(true, arrayStringsAreEqual(word1, LEN(word1), word2, LEN(word2)));
}

START_TEST(test_official_2) {
    char *word1[] = { "a", "cb" }, *word2[] = { "ab", "c" };
    ck_assert_int_eq(false, arrayStringsAreEqual(word1, LEN(word1), word2, LEN(word2)));
}

START_TEST(test_official_3) {
    char *word1[] = { "abc", "d", "defg" }, *word2[] = { "abcddefg" };
    ck_assert_int_eq(true, arrayStringsAreEqual(word1, LEN(word1), word2, LEN(word2)));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}