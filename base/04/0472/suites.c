/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/28 上午11:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0472.c"

int comp(const void *a, const void *b) {
    char *pa = *( char ** )a, *pb = *( char ** )b;
    return strcmp(pa, pb);
}

START_TEST(test_official_1) {
    int len;
    char *words[]  = { "cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat" };
    char *target[] = { "catsdogcats", "dogcatsdog", "ratcatdogcat" };
    char **ans     = findAllConcatenatedWordsInADict(words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), comp);
    qsort(target, len, sizeof(char *), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *words[]  = { "cat", "dog", "catdog" };
    char *target[] = { "catdog" };
    char **ans     = findAllConcatenatedWordsInADict(words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), comp);
    qsort(target, len, sizeof(char *), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_failed_1) {
    int len;
    char *words[]  = { "" };
    char *target[] = {};
    char **ans     = findAllConcatenatedWordsInADict(words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), comp);
    qsort(target, len, sizeof(char *), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_failed_2) {
    int len;
#include "failed.c"
    char **ans = findAllConcatenatedWordsInADict(words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), comp);
    qsort(target, len, sizeof(char *), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_tle) {
    int len;
#include "tle.c"
    char **ans = findAllConcatenatedWordsInADict(words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), comp);
    qsort(target, len, sizeof(char *), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}