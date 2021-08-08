/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/2 上午1:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0304.c"

START_TEST(test_official) {
    int col    = 5;
    int *arr[] = { (int[]) { 3, 0, 1, 4, 2 }, (int[]) { 5, 6, 3, 2, 1 }, (int[]) { 1, 2, 0, 1, 5 },
                   (int[]) { 4, 1, 0, 1, 7 }, (int[]) { 1, 0, 3, 0, 5 } };

    NumMatrix *matrix = numMatrixCreate(arr, LEN(arr), &col);
    ck_assert_ptr_nonnull(matrix);
    ck_assert_int_eq(8, numMatrixSumRegion(matrix, 2, 1, 4, 3));
    ck_assert_int_eq(11, numMatrixSumRegion(matrix, 1, 1, 2, 2));
    ck_assert_int_eq(12, numMatrixSumRegion(matrix, 1, 2, 2, 4));
    numMatrixFree(matrix);
}

START_TEST(test_failed) {
    int col = 0, *arr[] = {};
    NumMatrix *matrix = numMatrixCreate(arr, LEN(arr), &col);
    ck_assert_ptr_nonnull(matrix);
    numMatrixFree(matrix);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}