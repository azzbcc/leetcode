/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/21 下午6:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1489.c"

START_TEST(test_official_1) {
    int n = 5, *arr[] = { (int[]) { 0, 1, 1 }, (int[]) { 1, 2, 1 }, (int[]) { 2, 3, 2 }, (int[]) { 0, 3, 2 },
                          (int[]) { 0, 4, 3 }, (int[]) { 3, 4, 3 }, (int[]) { 1, 4, 6 } };
    int col[] = { 2, 4 }, target[][4] = { { 0, 1 }, { 2, 3, 4, 5 } };
    int len = 0, *returnColumnSizes = NULL;
    int **ans = findCriticalAndPseudoCriticalEdges(n, arr, LEN(arr), NULL, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(col[i], returnColumnSizes[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int n = 4, *arr[] = { (int[]) { 0, 1, 1 }, (int[]) { 1, 2, 1 }, (int[]) { 2, 3, 1 }, (int[]) { 0, 3, 1 } };
    int col[] = { 0, 4 }, target[][4] = { {}, { 0, 1, 2, 3 } };
    int len = 0, *returnColumnSizes = NULL;
    int **ans = findCriticalAndPseudoCriticalEdges(n, arr, LEN(arr), NULL, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(col[i], returnColumnSizes[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}