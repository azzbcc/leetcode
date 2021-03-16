/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/16 下午12:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0059.c"

START_TEST(test_official_1) {
    int n = 3, *target[] = { (int[]) { 1, 2, 3 }, (int[]) { 8, 9, 4 }, (int[]) { 7, 6, 5 } };
    int len, *returnColumnSizes;
    int **ans = generateMatrix(n, &len, &returnColumnSizes);
    ck_assert_int_eq(len, n);
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], n);
        ck_assert_mem_eq(ans[i], target[i], n * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int n = 1, *target[] = { (int[]) { 1 } };
    int len, *returnColumnSizes;
    int **ans = generateMatrix(n, &len, &returnColumnSizes);
    ck_assert_int_eq(len, n);
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], n);
        ck_assert_mem_eq(ans[i], target[i], n * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}