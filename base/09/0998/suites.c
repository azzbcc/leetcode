/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/30 上午11:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0998.c"

START_TEST(test_official_1) {
    int arr[] = { 4, 1, 3, null, null, 2 }, val = 5;
    int target[] = { 5, 4, null, 1, 3, null, null, 2 };
    tree_t t     = tree_create(target);
    tree_t ans   = insertIntoMaxTree(tree_create(arr), val);

    ck_assert(tree_equal(ans, t));
    tree_free(ans);
    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { 5, 2, 4, null, 1 }, val = 3;
    int target[] = { 5, 2, 4, null, 1, null, 3 };
    tree_t t     = tree_create(target);
    tree_t ans   = insertIntoMaxTree(tree_create(arr), val);

    ck_assert(tree_equal(ans, t));
    tree_free(ans);
    tree_free(t);
}

START_TEST(test_official_3) {
    int arr[] = { 5, 2, 3, null, 1 }, val = 4;
    int target[] = { 5, 2, 4, null, 1, 3 };
    tree_t t     = tree_create(target);
    tree_t ans   = insertIntoMaxTree(tree_create(arr), val);

    ck_assert(tree_equal(ans, t));
    tree_free(ans);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}