/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/11 下午6:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0865.c"

static tree_t tree_find(tree_t root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    tree_t left = tree_find(root->left, val);
    if (left) return left;
    return tree_find(root->right, val);
}

START_TEST(test_official) {
    int arr[] = { 3, 5, 1, 6, 2, 0, 8, null, null, 7, 4 };
    tree_t t  = tree_create(arr, sizeof(arr) / sizeof(arr[0]));

    tree_t target = tree_find(t, 2), ans = subtreeWithAllDeepest(t);

    fail_unless(tree_equal(target, ans));

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}