/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/5 上午11:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0830.c"

START_TEST(test_official_1) {
    char *s = "abbxxxxzzy";
    int len = 0, *returnColumnSizes = NULL;
    int **ans       = largeGroupPositions(s, &len, &returnColumnSizes);
    int target[][2] = { { 3, 6 } };

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    char *s = "abc";
    int len = 0, *returnColumnSizes = NULL;
    int **ans       = largeGroupPositions(s, &len, &returnColumnSizes);
    int target[][2] = {};

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_3) {
    char *s = "abcdddeeeeaabbbcd";
    int len = 0, *returnColumnSizes = NULL;
    int **ans       = largeGroupPositions(s, &len, &returnColumnSizes);
    int target[][2] = { { 3, 5 }, { 6, 9 }, { 12, 14 } };

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_4) {
    char *s = "aba";
    int len = 0, *returnColumnSizes = NULL;
    int **ans       = largeGroupPositions(s, &len, &returnColumnSizes);
    int target[][2] = {};

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed) {
    char *s = "aaa";
    int len = 0, *returnColumnSizes = NULL;
    int **ans       = largeGroupPositions(s, &len, &returnColumnSizes);
    int target[][2] = { { 0, 2 } };

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}