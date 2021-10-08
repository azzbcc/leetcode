/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/8 上午11:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0187.c"

START_TEST(test_official_1) {
    int len;
    char *s        = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    char *target[] = { "AAAAACCCCC", "CCCCCAAAAA" };
    char **ans     = findRepeatedDnaSequences(s, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *s        = "AAAAAAAAAAAAA";
    char *target[] = { "AAAAAAAAAA" };
    char **ans     = findRepeatedDnaSequences(s, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len;
    char *s        = "AAAAAAAAAAA";
    char *target[] = { "AAAAAAAAAA" };
    char **ans     = findRepeatedDnaSequences(s, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}