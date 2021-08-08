/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/26 上午13:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0113.c"

START_TEST(test_official) {
    int sum = 22, arr[]        = { 5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1 };
    int len, *returncolumnsize = NULL;
    tree_t t = tree_create(arr);

    int col[] = { 4, 4 }, target[][4] = { { 5, 4, 11, 2 }, { 5, 8, 4, 5 } };
    int **ans = pathSum(t, sum, &len, &returncolumnsize);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(col[i], returncolumnsize[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(returncolumnsize);
    tree_free(t);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}
