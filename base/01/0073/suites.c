/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/21 下午5:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0073.c"

START_TEST(test_official_1) {
    int col       = 3;
    int *matrix[] = { (int[]) { 1, 1, 1 }, (int[]) { 1, 0, 1 }, (int[]) { 1, 1, 1 } };
    int *target[] = { (int[]) { 1, 0, 1 }, (int[]) { 0, 0, 0 }, (int[]) { 1, 0, 1 } };

    setZeroes(matrix, LEN(matrix), &col);
    for (int i = 0; i < LEN(target); ++i) {
        ck_assert_mem_eq(matrix[i], target[i], col * sizeof(int));
    }
}

START_TEST(test_official_2) {
    int col       = 4;
    int *matrix[] = { (int[]) { 0, 1, 2, 0 }, (int[]) { 3, 4, 5, 2 }, (int[]) { 1, 3, 1, 5 } };
    int *target[] = { (int[]) { 0, 0, 0, 0 }, (int[]) { 0, 4, 5, 0 }, (int[]) { 0, 3, 1, 0 } };

    setZeroes(matrix, LEN(matrix), &col);
    for (int i = 0; i < LEN(target); ++i) {
        ck_assert_mem_eq(matrix[i], target[i], col * sizeof(int));
    }
}

START_TEST(test_failed) {
    int col       = 3;
    int *matrix[] = { (int[]) { 1, 1, 1 }, (int[]) { 1, 0, 1 }, (int[]) { 1, 1, -10000 } };
    int *target[] = { (int[]) { 1, 0, 1 }, (int[]) { 0, 0, 0 }, (int[]) { 1, 0, -10000 } };

    setZeroes(matrix, LEN(matrix), &col);
    for (int i = 0; i < LEN(target); ++i) {
        ck_assert_mem_eq(matrix[i], target[i], col * sizeof(int));
    }
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}