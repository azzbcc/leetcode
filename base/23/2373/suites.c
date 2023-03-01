/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/1 上午9:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2373.c"

START_TEST(test_official_1) {
    int len = 0, *returnColumnSizes = NULL;
    int *grid[]   = { (int[]) { 9, 9, 8, 1 }, (int[]) { 5, 6, 2, 6 }, (int[]) { 8, 2, 6, 4 }, (int[]) { 6, 2, 2, 2 } };
    int *target[] = { (int[]) { 9, 9 }, (int[]) { 8, 6 } };
    int **ans     = largestLocal(grid, LEN(grid), NULL, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], len);
        ck_assert_mem_eq(ans[i], target[i], returnColumnSizes[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int len = 0, *returnColumnSizes = NULL;
    int *grid[]   = { (int[]) { 1, 1, 1, 1, 1 }, (int[]) { 1, 1, 1, 1, 1 }, (int[]) { 1, 1, 2, 1, 1 },
                      (int[]) { 1, 1, 1, 1, 1 }, (int[]) { 1, 1, 1, 1, 1 } };
    int *target[] = { (int[]) { 2, 2, 2 }, (int[]) { 2, 2, 2 }, (int[]) { 2, 2, 2 } };
    int **ans     = largestLocal(grid, LEN(grid), NULL, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], len);
        ck_assert_mem_eq(ans[i], target[i], returnColumnSizes[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}