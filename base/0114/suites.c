/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/3 上午11:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0114.c"

START_TEST(test_official) {
    int arr[] = { 1, 2, 5, 3, 4, null, 6, null, null, null, null }, target[128] = { 0 };
    for (int i = 0, pos = 0; i < 6; ++i, pos = pos * 2 + 2) {
        target[pos]         = i + 1;
        target[pos * 2 + 1] = null;
        target[pos * 2 + 2] = null;
    }

    tree_t ta = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));
    tree_t tt = tree_create(target, 0, sizeof(target) / sizeof(target[0]));

    flatten(ta);

    fail_if(!tree_equal(ta, tt));

    tree_free(ta);
    tree_free(tt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}