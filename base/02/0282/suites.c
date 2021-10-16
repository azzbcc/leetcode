/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/16 下午10:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0282.c"

int cmp(const void *a, const void *b) {
    char *pa = *( char ** )a, *pb = *( char ** )b;
    return strcmp(pa, pb);
}

START_TEST(test_official_1) {
    char *num = "123";
    int len, key = 6;
    char *target[] = { "1+2+3", "1*2*3" };
    char **ans     = addOperators(num, key, &len);

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
    char *num = "232";
    int len, key = 8;
    char *target[] = { "2*3+2", "2+3*2" };
    char **ans     = addOperators(num, key, &len);

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
    char *num = "105";
    int len, key = 5;
    char *target[] = { "1*0+5", "10-5" };
    char **ans     = addOperators(num, key, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), cmp);
    qsort(target, len, sizeof(char *), cmp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_4) {
    char *num = "00";
    int len, key = 0;
    char *target[] = { "0+0", "0-0", "0*0" };
    char **ans     = addOperators(num, key, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), cmp);
    qsort(target, len, sizeof(char *), cmp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_5) {
    char *num = "3456237490";
    int len, key = 9191;
    char *target[] = {};
    char **ans     = addOperators(num, key, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(char *), cmp);
    qsort(target, len, sizeof(char *), cmp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_limit) {
    char *num = "1000000009";
    int len, key = 9, target = 3280;
    char **ans = addOperators(num, key, &len);

    ck_assert_int_eq(len, target);
    for (int i = 0; i < len; free(ans[i++])) {}
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}