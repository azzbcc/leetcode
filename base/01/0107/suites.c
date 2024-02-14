/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/6 下午12:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0107.c"

START_TEST(test_official_1) {
    int len, *returnColumnSizes;
    int arr[] = { 3, 9, 20, null, null, 15, 7 }, col[] = { 2, 2, 1 };
    int *target[] = { (int[]) { 15, 7 }, (int[]) { 9, 20 }, (int[]) { 3 } };

    tree_t t  = tree_create(arr);
    int **ans = levelOrderBottom(t, &len, &returnColumnSizes);
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
    int len, *returnColumnSizes;
    int arr[] = { 1 }, col[] = { 1 }, *target[] = { (int[]) { 1 } };
    tree_t t  = tree_create(arr);
    int **ans = levelOrderBottom(t, &len, &returnColumnSizes);
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
    int len, *returnColumnSizes;
    int arr[] = {}, col[] = {}, *target[] = {};
    tree_t t  = tree_create(arr);
    int **ans = levelOrderBottom(t, &len, &returnColumnSizes);
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