/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/27 上午11:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0301.c"

int cmp(const void *a, const void *b) {
    char *pa = *( char ** )a;
    char *pb = *( char ** )b;
    return strcmp(pa, pb);
}

START_TEST(test_official_1) {
    int len;
    char *s        = "()())()";
    char *target[] = { "(())()", "()()()" };
    char **ans     = removeInvalidParentheses(s, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), cmp);
    qsort(target, len, sizeof(char *), cmp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *s        = "(a)())()";
    char *target[] = { "(a())()", "(a)()()" };
    char **ans     = removeInvalidParentheses(s, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), cmp);
    qsort(target, len, sizeof(char *), cmp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len;
    char *s        = ")(";
    char *target[] = { "" };
    char **ans     = removeInvalidParentheses(s, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), cmp);
    qsort(target, len, sizeof(char *), cmp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}