/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/27 上午11:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0235.c"

START_TEST(test_official_1) {
    int p = 2, q = 8, target = 6;
    int arr[] = { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 };
    tree_t t  = tree_create(arr);

    tree_t ans = lowestCommonAncestor(t, tree_find(t, p), tree_find(t, q));

    ck_assert(tree_equal(ans, tree_find(t, target)));

    tree_free(t);
}

START_TEST(test_official_2) {
    int p = 2, q = 4, target = 2;
    int arr[] = { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 };
    tree_t t  = tree_create(arr);

    tree_t ans = lowestCommonAncestor(t, tree_find(t, p), tree_find(t, q));

    ck_assert(tree_equal(ans, tree_find(t, target)));

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}
