/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/24 上午12:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0832.c"

START_TEST(test_official_1) {
    int len, *returnColumnSizes = NULL, col = 3;
    int *A[]      = { (int[]) { 1, 1, 0 }, (int[]) { 1, 0, 1 }, (int[]) { 0, 0, 0 } };
    int *target[] = { (int[]) { 1, 0, 0 }, (int[]) { 0, 1, 0 }, (int[]) { 1, 1, 1 } };
    int **ans     = flipAndInvertImage(A, LEN(A), &col, &len, &returnColumnSizes);

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
    int len, *returnColumnSizes = NULL, col = 4;
    int *A[]      = { (int[]) { 1, 1, 0, 0 }, (int[]) { 1, 0, 0, 1 }, (int[]) { 0, 1, 1, 1 }, (int[]) { 1, 0, 1, 0 } };
    int *target[] = { (int[]) { 1, 1, 0, 0 }, (int[]) { 0, 1, 1, 0 }, (int[]) { 0, 0, 0, 1 }, (int[]) { 1, 0, 1, 0 } };
    int **ans     = flipAndInvertImage(A, LEN(A), &col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        ck_assert_mem_eq(ans[i], target[i], col * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}