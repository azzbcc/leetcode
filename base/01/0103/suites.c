/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/22 上午11:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0103.c"

START_TEST(test_official) {
    int arr[] = { 3, 9, 20, null, null, 15, 7 };
    tree_t t  = tree_create(arr);
    int len, *returnColumnSizes, **ans = zigzagLevelOrder(t, &len, &returnColumnSizes);
    int target[][2] = { { 3 }, { 20, 9 }, { 15, 7 } }, col[] = { 1, 2, 2 };

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}