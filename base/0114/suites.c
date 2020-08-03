/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/3 上午11:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>
#include <check_stdint.h>
#include <stdbool.h>

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

bool tree_equal(tree_t t1, tree_t t2) {
    if (t1 == t2) return true;
    if (!t1 || !t2) return false;

    return t1->val == t2->val && tree_equal(t1->left, t2->left) && tree_equal(t1->right, t2->right);
}

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