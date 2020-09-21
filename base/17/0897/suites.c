/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/21 上午11:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0897.c"

START_TEST(test_official) {
    int arr[]     = { 5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9 };
    int tar[]     = { 1, null, 2, null, 3, null, 4, null, 5, null, 6, null, 7, null, 8, null, 9 };
    tree_t ta     = tree_create(arr, sizeof(arr) / sizeof(arr[0]));
    tree_t target = tree_create(tar, sizeof(tar) / sizeof(tar[0]));

    tree_t ans = increasingBST(ta);

    ck_assert(tree_equal(target, ans));

    tree_free(ans);
    tree_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}