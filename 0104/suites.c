/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/28 上午11:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <assert.h>
#include <stdlib.h>
#include <check_stdint.h>

#define null INT32_MIN

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} * tree_t;

tree_t tree_create(int data[], int cur, int len) {
    if (len <= cur || data[cur] == null) return NULL;

    tree_t t = calloc(1, sizeof(struct TreeNode));
    t->val   = data[cur];
    t->left  = tree_create(data, 2 * cur + 1, len);
    t->right = tree_create(data, 2 * cur + 2, len);

    return t;
}

void *tree_free(tree_t t) {
    if (t->left) tree_free(t->left);
    if (t->right) tree_free(t->right);
    free(t);
}

#include "0104.c"

START_TEST(test_official) {
    int arr[] = { 3, 9, 20, null, null, 15, 7 }, target = 3;
    tree_t tree = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    int depth = maxDepth(tree);
    ck_assert_msg(depth == target, "error, except %d but got %d on maxDepth(3, 9, 20, null, null, 15, 7).", target,
                  depth);

    tree_free(tree);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}