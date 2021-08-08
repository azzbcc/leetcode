/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/30 上午11:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0701.c"

START_TEST(test_official) {
    int arr[] = { 4, 2, 7, 1, 3 }, target[] = { 4, 2, 7, 1, 3, 5 };
    tree_t ta = tree_create(arr);
    tree_t tt = tree_create(target);

    tree_t ans = insertIntoBST(ta, 5);

    ck_assert(tree_equal(ans, tt));

    tree_free(tt);
    tree_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}