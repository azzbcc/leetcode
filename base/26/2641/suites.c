/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/7 14:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "2641.c"

START_TEST(test_official_1) {
    int arr[] = { 5, 4, 9, 1, 10, null, 7 }, target[] = { 0, 0, 0, 7, 7, null, 11 };
    tree_t ta = tree_create(arr), tt = tree_create(target);

    tree_t ans = replaceValueInTree(ta);
    ck_assert(tree_equal(ans, tt));

    tree_free(ans);
    tree_free(tt);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 1, 2 }, target[] = { 0, 0, 0 };
    tree_t ta = tree_create(arr), tt = tree_create(target);

    tree_t ans = replaceValueInTree(ta);
    ck_assert(tree_equal(ans, tt));

    tree_free(ans);
    tree_free(tt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}