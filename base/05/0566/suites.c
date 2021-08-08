/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/17 下午10:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0566.c"

START_TEST(test_official_1) {
    int a_col = 2, *arr[] = { (int[]) { 1, 2 }, (int[]) { 3, 4 } };
    int t_col = 4, *target[] = { (int[]) { 1, 2, 3, 4 } };
    int r = 1, c = 4, len, *returnColumnSizes = NULL;
    int **ans = matrixReshape(arr, LEN(arr), &a_col, r, c, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(t_col, returnColumnSizes[i]);
        ck_assert_mem_eq(ans[i], target[i], t_col * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int a_col = 2, *arr[] = { (int[]) { 1, 2 }, (int[]) { 3, 4 } };
    int t_col = 2, *target[] = { (int[]) { 1, 2 }, (int[]) { 3, 4 } };
    int r = 2, c = 4, len, *returnColumnSizes = NULL;
    int **ans = matrixReshape(arr, LEN(arr), &a_col, r, c, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(t_col, returnColumnSizes[i]);
        ck_assert_mem_eq(ans[i], target[i], t_col * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}