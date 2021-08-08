/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/31 上午8:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0987.c"

START_TEST(test_official_1) {
    int col[]     = { 1, 2, 1, 1 };
    int arr[]     = { 3, 9, 20, null, null, 15, 7 };
    int *target[] = { (int[]) { 9 }, (int[]) { 3, 15 }, (int[]) { 20 }, (int[]) { 7 } };

    int len, *returnColumnSizes;
    tree_t t  = tree_create(arr);
    int **ans = verticalTraversal(t, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    tree_free(t);
    free(ans);
}

START_TEST(test_official_2) {
    int col[]     = { 1, 1, 3, 1, 1 };
    int arr[]     = { 1, 2, 3, 4, 5, 6, 7 };
    int *target[] = { (int[]) { 4 }, (int[]) { 2 }, (int[]) { 1, 5, 6 }, (int[]) { 3 }, (int[]) { 7 } };

    int len, *returnColumnSizes;
    tree_t t  = tree_create(arr);
    int **ans = verticalTraversal(t, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    tree_free(t);
    free(ans);
}

START_TEST(test_official_3) {
    int col[]     = { 1, 1, 3, 1, 1 };
    int arr[]     = { 1, 2, 3, 4, 6, 5, 7 };
    int *target[] = { (int[]) { 4 }, (int[]) { 2 }, (int[]) { 1, 5, 6 }, (int[]) { 3 }, (int[]) { 7 } };

    int len, *returnColumnSizes;
    tree_t t  = tree_create(arr);
    int **ans = verticalTraversal(t, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    tree_free(t);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}