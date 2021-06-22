/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/22 上午10:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "offer_38.c"

static int comp(const void *a, const void *b) {
    char *pa = *( char ** )a, *pb = *( char ** )b;
    return strcmp(pa, pb);
}

START_TEST(test_official) {
    int len;
    char *s        = "abc";
    char *target[] = { "abc", "acb", "bac", "bca", "cab", "cba" };
    char **ans     = permutation(s, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), comp);
    qsort(target, len, sizeof(char *), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}
START_TEST(test_own) {
    int len;
    char *s        = "aabc";
    char *target[] = { "abac", "abca", "acab", "acba", "aabc", "aacb", "baca", "baac", "bcaa", "caba", "caab", "cbaa" };
    char **ans     = permutation(s, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), comp);
    qsort(target, len, sizeof(char *), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}