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

START_TEST(test_official) {
    int arr[]       = { 3, 9, 20, null, null, 15, 7 };
    int colSizes[]  = { 2, 2, 1 };
    int target[][2] = { { 15, 7 }, { 9, 20 }, { 3 } };
    int len = 0, *returnColumnSizes = NULL;

    tree_t tree = tree_create(arr);
    int **ans   = levelOrderBottom(tree, &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(colSizes[i], returnColumnSizes[i]);
        ck_assert_mem_eq(target[i], ans[i], colSizes[i] * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    tree_free(tree);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}
