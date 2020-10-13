/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/13 下午6:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0030.c"

START_TEST(test_official_1) {
    char *s = "barfoothefoobarman", *words[] = { "foo", "bar" };
    int len, target[] = { 0, 9 }, *ans = findSubstring(s, words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    char *s = "wordgoodgoodgoodbestword", *words[] = { "word", "good", "best", "word" };
    int len, target[] = {}, *ans = findSubstring(s, words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_failed_1) {
    char *s = "barfoofoobarthefoobarman", *words[] = { "bar", "foo", "the" };
    int len, target[] = { 6, 9, 12 }, *ans = findSubstring(s, words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_failed_2) {
    char *s = "aaaaaaaaaaaaaa", *words[] = { "aa", "aa" };
    int len, target[] = { 0, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 }, *ans = findSubstring(s, words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_failed_3) {
    char *s = "mississippi", *words[] = { "is" };
    int len, target[] = { 4, 1 }, *ans = findSubstring(s, words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}