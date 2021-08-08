/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/25 下午12:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0867.c"

START_TEST(test_official_1) {
    int len, *returnColumnSizes = NULL, col = 3;
    int *matrix[] = { (int[]) { 1, 2, 3 }, (int[]) { 4, 5, 6 }, (int[]) { 7, 8, 9 } };
    int *target[] = { (int[]) { 1, 4, 7 }, (int[]) { 2, 5, 8 }, (int[]) { 3, 6, 9 } };
    int **ans     = transpose(matrix, LEN(matrix), &col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(matrix));
        ck_assert_mem_eq(ans[i], target[i], LEN(matrix) * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int len, *returnColumnSizes = NULL, col = 3;
    int *matrix[] = { (int[]) { 1, 2, 3 }, (int[]) { 4, 5, 6 } };
    int *target[] = { (int[]) { 1, 4 }, (int[]) { 2, 5 }, (int[]) { 3, 6 } };
    int **ans     = transpose(matrix, LEN(matrix), &col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(matrix));
        ck_assert_mem_eq(ans[i], target[i], LEN(matrix) * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}