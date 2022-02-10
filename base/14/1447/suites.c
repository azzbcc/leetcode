/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/10 上午11:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1447.c"

int comp(const void *a, const void *b) {
    return strcmp(*( char ** )a, *( char ** )b);
}

START_TEST(test_official_1) {
    int len, n = 2;
    char *target[] = { "1/2" };
    char **ans     = simplifiedFractions(n, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), comp);
    qsort(target, len, sizeof(char *), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len, n = 3;
    char *target[] = { "1/2", "1/3", "2/3" };
    char **ans     = simplifiedFractions(n, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), comp);
    qsort(target, len, sizeof(char *), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len, n = 4;
    char *target[] = { "1/2", "1/3", "1/4", "2/3", "3/4" };
    char **ans     = simplifiedFractions(n, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), comp);
    qsort(target, len, sizeof(char *), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_4) {
    int len, n = 1;
    char *target[] = {};
    char **ans     = simplifiedFractions(n, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), comp);
    qsort(target, len, sizeof(char *), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_limit) {
#include "limit.c"
    int len, n = 100;
    char **ans = simplifiedFractions(n, &len);

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
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}