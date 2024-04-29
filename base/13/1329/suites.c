/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/29 10:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1329.c"

START_TEST(test_official_1) {
    int len = 0, *returnColumnSizes = NULL;
    int col = 4, *mat[] = { (int[]) { 3, 3, 1, 1 }, (int[]) { 2, 2, 1, 2 }, (int[]) { 1, 1, 1, 2 } };
    int *target[] = { (int[]) { 1, 1, 1, 1 }, (int[]) { 1, 2, 2, 2 }, (int[]) { 1, 2, 3, 3 } };
    int **ans     = diagonalSort(mat, LEN(mat), &col, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int len = 0, *returnColumnSizes = NULL;
    int col = 6, *mat[] = { (int[]) { 11, 25, 66, 1, 69, 7 }, (int[]) { 23, 55, 17, 45, 15, 52 },
                            (int[]) { 75, 31, 36, 44, 58, 8 }, (int[]) { 22, 27, 33, 25, 68, 4 },
                            (int[]) { 84, 28, 14, 11, 5, 50 } };
    int *target[] = { (int[]) { 5, 17, 4, 1, 52, 7 }, (int[]) { 11, 11, 25, 45, 8, 69 },
                      (int[]) { 14, 23, 25, 44, 58, 15 }, (int[]) { 22, 27, 31, 36, 50, 66 },
                      (int[]) { 84, 28, 75, 33, 55, 68 } };
    int **ans     = diagonalSort(mat, LEN(mat), &col, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}