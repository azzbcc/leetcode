/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/7 下午2:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0131.c"

START_TEST(test_official_1) {
    char *s = "aab";
    int len, col[] = { 3, 2 }, *returnColumnSizes = NULL;
    char **target[] = { (char *[]) { "a", "a", "b" }, (char *[]) { "aa", "b" } };

    char ***ans = partition(s, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col[i]);
        for (int j = 0; j < col[i]; ++j) {
            ck_assert_str_eq(ans[i][j], target[i][j]);
            free(ans[i][j]);
        }
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    char *s = "a";
    int len, col[] = { 1 }, *returnColumnSizes = NULL;
    char **target[] = { (char *[]) { "a" } };

    char ***ans = partition(s, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col[i]);
        for (int j = 0; j < col[i]; ++j) {
            ck_assert_str_eq(ans[i][j], target[i][j]);
            free(ans[i][j]);
        }
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed) {
    char *s = "fffffffffffffff";
    int len, *returnColumnSizes = NULL;
    char **target[16384] = {};

    char ***ans = partition(s, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            free(ans[i][j]);
        }
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}