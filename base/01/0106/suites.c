/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/25 上午11:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0106.c"

START_TEST(test_official) {
    int arr1[] = { 9, 3, 15, 20, 7 }, arr2[] = { 9, 15, 7, 20, 3 };
    int target[] = { 3, 9, 20, null, null, 15, 7 };

    tree_t tt = tree_create(target);
    tree_t ta = buildTree(arr1, sizeof(arr1) / sizeof(arr1[0]), arr2, sizeof(arr2) / sizeof(arr2[0]));

    ck_assert(tree_equal(tt, ta));

    tree_free(tt);
    tree_free(ta);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}