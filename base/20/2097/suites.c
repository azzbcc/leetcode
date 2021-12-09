/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/6 下午6:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2097.c"

START_TEST(test_official_1) {
    int col = 2;
    int len = 0, *returnColumnSizes = NULL;
    int *pairs[]  = { (int[]) { 5, 1 }, (int[]) { 4, 5 }, (int[]) { 11, 9 }, (int[]) { 9, 4 } };
    int *target[] = { (int[]) { 11, 9 }, (int[]) { 9, 4 }, (int[]) { 4, 5 }, (int[]) { 5, 1 } };

    int **ans = validArrangement(pairs, LEN(pairs), NULL, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        ck_assert_mem_eq(ans[i], target[i], col * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int col = 2;
    int len = 0, *returnColumnSizes = NULL;
    int *pairs[]  = { (int[]) { 1, 3 }, (int[]) { 3, 2 }, (int[]) { 2, 1 } };
    int *target[] = { (int[]) { 1, 3 }, (int[]) { 3, 2 }, (int[]) { 2, 1 } };

    int **ans = validArrangement(pairs, LEN(pairs), NULL, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        ck_assert_mem_eq(ans[i], target[i], col * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_3) {
    int col = 2;
    int len = 0, *returnColumnSizes = NULL;
    int *pairs[]  = { (int[]) { 1, 2 }, (int[]) { 1, 3 }, (int[]) { 2, 1 } };
    int *target[] = { (int[]) { 1, 2 }, (int[]) { 2, 1 }, (int[]) { 1, 3 } };

    int **ans = validArrangement(pairs, LEN(pairs), NULL, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        ck_assert_mem_eq(ans[i], target[i], col * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_tle) {
    int col = 2, maxn = 100000;
    int len = 0, *returnColumnSizes = NULL;
    int grid[maxn][2], *pairs[maxn];
    for (int i = 0; i < maxn; ++i) {
        grid[i][0] = i, grid[i][1] = (i + 1) % maxn, pairs[i] = grid[i];
    }

    int **ans = validArrangement(pairs, LEN(pairs), NULL, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(pairs));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        ck_assert_mem_eq(ans[i], pairs[i], col * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}