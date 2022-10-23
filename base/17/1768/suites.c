/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/23 下午1:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1768.c"

START_TEST(test_official_1) {
    char *word1 = "abc", *word2 = "pqr";
    char *target = "apbqcr", *ans = mergeAlternately(word1, word2);
    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_official_2) {
    char *word1 = "ab", *word2 = "pqrs";
    char *target = "apbqrs", *ans = mergeAlternately(word1, word2);
    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_official_3) {
    char *word1 = "abcd", *word2 = "pq";
    char *target = "apbqcd", *ans = mergeAlternately(word1, word2);
    ck_assert_str_eq(ans, target);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}