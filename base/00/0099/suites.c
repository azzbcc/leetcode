/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/8 下午12:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0099.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 3, null, null, 2 }, target[] = { 3, 1, null, null, 2 };

    tree_t ta = tree_create(arr);
    tree_t tt = tree_create(target);

    recoverTree(ta);

    fail_if(!tree_equal(ta, tt));

    tree_free(ta);
    tree_free(tt);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 1, 4, null, null, 2 }, target[] = { 2, 1, 4, null, null, 3 };

    tree_t ta = tree_create(arr);
    tree_t tt = tree_create(target);

    recoverTree(ta);

    fail_if(!tree_equal(ta, tt));

    tree_free(ta);
    tree_free(tt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}