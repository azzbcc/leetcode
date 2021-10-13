/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/13 上午11:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1487.c"

START_TEST(test_official_1) {
    int len;
    char *names[]  = { "pes", "fifa", "gta", "pes(2019)" };
    char *target[] = { "pes", "fifa", "gta", "pes(2019)" };
    char **ans     = getFolderNames(names, LEN(names), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *names[]  = { "gta", "gta(1)", "gta", "avalon" };
    char *target[] = { "gta", "gta(1)", "gta(2)", "avalon" };
    char **ans     = getFolderNames(names, LEN(names), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len;
    char *names[]  = { "onepiece", "onepiece(1)", "onepiece(2)", "onepiece(3)", "onepiece" };
    char *target[] = { "onepiece", "onepiece(1)", "onepiece(2)", "onepiece(3)", "onepiece(4)" };
    char **ans     = getFolderNames(names, LEN(names), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_4) {
    int len;
    char *names[]  = { "wano", "wano", "wano", "wano" };
    char *target[] = { "wano", "wano(1)", "wano(2)", "wano(3)" };
    char **ans     = getFolderNames(names, LEN(names), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_5) {
    int len;
    char *names[]  = { "kaido", "kaido(1)", "kaido", "kaido(1)" };
    char *target[] = { "kaido", "kaido(1)", "kaido(2)", "kaido(1)(1)" };
    char **ans     = getFolderNames(names, LEN(names), &len);

    ck_assert_int_eq(len, LEN(target));
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
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}