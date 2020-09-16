/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/16 上午11:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0226.c"

START_TEST(test_official) {
    int arr[][7] = { { 4, 2, 7, 1, 3, 6, 9 }, { 4, 7, 2, 9, 6, 3, 1 } };
    tree_t ta = tree_create(arr[0], 7), tt = tree_create(arr[1], 7);

    fail_unless(tree_equal(invertTree(ta), tt));

    tree_free(ta);
    tree_free(tt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}