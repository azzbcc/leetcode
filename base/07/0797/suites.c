/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/25 上午10:41
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0797.c"

START_TEST(test_official_1) {
    int *graph[]  = { (int[]) { 1, 2 }, (int[]) { 3 }, (int[]) { 3 }, (int[]) {} };
    int *target[] = { (int[]) { 0, 1, 3 }, (int[]) { 0, 2, 3 } };
    int g_col[] = { 2, 1, 1, 0 }, t_col[] = { 3, 3 };
    int len, *returnColumnSizes;
    int **ans = allPathsSourceTarget(graph, LEN(graph), g_col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], t_col[i]);
        ck_assert_mem_eq(ans[i], target[i], t_col[i] * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

START_TEST(test_official_2) {
    int *graph[]  = { (int[]) { 4, 3, 1 }, (int[]) { 3, 2, 4 }, (int[]) { 3 }, (int[]) { 4 }, (int[]) {} };
    int *target[] = { (int[]) { 0, 4 }, (int[]) { 0, 3, 4 }, (int[]) { 0, 1, 3, 4 }, (int[]) { 0, 1, 2, 3, 4 },
                      (int[]) { 0, 1, 4 } };
    int g_col[] = { 3, 3, 1, 1, 0 }, t_col[] = { 2, 3, 4, 5, 3 };
    int len, *returnColumnSizes;
    int **ans = allPathsSourceTarget(graph, LEN(graph), g_col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], t_col[i]);
        ck_assert_mem_eq(ans[i], target[i], t_col[i] * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

START_TEST(test_official_3) {
    int *graph[]  = { (int[]) { 1 }, (int[]) {} };
    int *target[] = { (int[]) { 0, 1 } };
    int g_col[] = { 1, 0 }, t_col[] = { 2 };
    int len, *returnColumnSizes;
    int **ans = allPathsSourceTarget(graph, LEN(graph), g_col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], t_col[i]);
        ck_assert_mem_eq(ans[i], target[i], t_col[i] * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

START_TEST(test_official_4) {
    int *graph[]  = { (int[]) { 1, 2, 3 }, (int[]) { 2 }, (int[]) { 3 }, (int[]) {} };
    int *target[] = { (int[]) { 0, 1, 2, 3 }, (int[]) { 0, 2, 3 }, (int[]) { 0, 3 } };
    int g_col[] = { 3, 1, 1, 0 }, t_col[] = { 4, 3, 2 };
    int len, *returnColumnSizes;
    int **ans = allPathsSourceTarget(graph, LEN(graph), g_col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], t_col[i]);
        ck_assert_mem_eq(ans[i], target[i], t_col[i] * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

START_TEST(test_official_5) {
    int *graph[]  = { (int[]) { 1, 3 }, (int[]) { 2 }, (int[]) { 3 }, (int[]) {} };
    int *target[] = { (int[]) { 0, 1, 2, 3 }, (int[]) { 0, 3 } };
    int g_col[] = { 2, 1, 1, 0 }, t_col[] = { 4, 2 };
    int len, *returnColumnSizes;
    int **ans = allPathsSourceTarget(graph, LEN(graph), g_col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], t_col[i]);
        ck_assert_mem_eq(ans[i], target[i], t_col[i] * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

START_TEST(test_limit) {
    const int max = 15;
    int *graph[max], data[max][max], g_col[max];
    for (int i = 0; i < max; ++i) {
        g_col[i] = max - i - 1, graph[i] = data[i];
        for (int j = 0; j < g_col[i]; ++j) {
            data[i][j] = i + j + 1;
        }
    }
    int len, *returnColumnSizes;
    int **ans = allPathsSourceTarget(graph, LEN(graph), g_col, &len, &returnColumnSizes);

    for (int i = 0; i < len; free(ans[i++])) {}
    free(returnColumnSizes);
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