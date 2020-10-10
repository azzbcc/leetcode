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
    int arr[] = { 1, 2, 5, 3, 4, null, 6 }, target[] = { 1, null, 2, null, 3, null, 4, null, 5, null, 6 };

    tree_t ta = tree_create(arr);
    tree_t tt = tree_create(target);

    flatten(ta);

    fail_if(!tree_equal(ta, tt));

    tree_free(ta);
    tree_free(tt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}
