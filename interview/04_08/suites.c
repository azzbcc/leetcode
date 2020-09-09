/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/9 下午7:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "04_08.c"

static tree_t tree_find(tree_t root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    tree_t left = tree_find(root->left, val);
    if (left) return left;
    return tree_find(root->right, val);
}

START_TEST(test_official_1) {
    int arr[]   = { 3, 5, 1, 6, 2, 0, 8, null, null, 7, 4 };
    tree_t root = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    tree_t target = tree_find(root, 3), ans = lowestCommonAncestor(root, tree_find(root, 5), tree_find(root, 1));
    fail_unless(tree_equal(target, ans));

    tree_free(root);
}
START_TEST(test_official_2) {
    int arr[]   = { 3, 5, 1, 6, 2, 0, 8, null, null, 7, 4 };
    tree_t root = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    tree_t target = tree_find(root, 5), ans = lowestCommonAncestor(root, tree_find(root, 5), tree_find(root, 4));
    fail_unless(tree_equal(target, ans));

    tree_free(root);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}