/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/12 12:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2085.c"

START_TEST(test_official_1) {
    char *words1[] = { "leetcode", "is", "amazing", "as", "is" }, *words2[] = { "amazing", "leetcode", "is" };
    int target = 2, ans = countWords(words1, LEN(words1), words2, LEN(words2));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *words1[] = { "b", "bb", "bbb" }, *words2[] = { "a", "aa", "aaa" };
    int target = 0, ans = countWords(words1, LEN(words1), words2, LEN(words2));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *words1[] = { "a", "ab" }, *words2[] = { "a", "a", "a", "ab" };
    int target = 1, ans = countWords(words1, LEN(words1), words2, LEN(words2));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}