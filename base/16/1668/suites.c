/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/3 下午1:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1668.c"

START_TEST(test_official_1) {
    char *sequence = "ababc", *word = "ab";
    ck_assert_int_eq(2, maxRepeating(sequence, word));
}

START_TEST(test_official_2) {
    char *sequence = "ababc", *word = "ba";
    ck_assert_int_eq(1, maxRepeating(sequence, word));
}

START_TEST(test_official_3) {
    char *sequence = "ababc", *word = "ac";
    ck_assert_int_eq(0, maxRepeating(sequence, word));
}

START_TEST(test_own) {
    char *sequence = "abcabcababcab", *word = "abcab";
    ck_assert_int_eq(2, maxRepeating(sequence, word));
}

START_TEST(test_failed) {
    char *sequence = "a", *word = "aaa";
    ck_assert_int_eq(0, maxRepeating(sequence, word));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}