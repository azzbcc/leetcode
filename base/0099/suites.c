/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/8 下午12:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

bool tree_equal(tree_t t1, tree_t t2) {
    if (t1 == t2) return true;
    if (!t1 || !t2) return false;

    return t1->val == t2->val && tree_equal(t1->left, t2->left) && tree_equal(t1->right, t2->right);
}

#include "0099.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 3, null, null, 2 }, target[] = { 3, 1, null, null, 2 };

    tree_t ta = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));
    tree_t tt = tree_create(target, 0, sizeof(target) / sizeof(target[0]));

    recoverTree(ta);

    fail_if(!tree_equal(ta, tt));

    tree_free(ta);
    tree_free(tt);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 1, 4, null, null, 2 }, target[] = { 2, 1, 4, null, null, 3 };

    tree_t ta = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));
    tree_t tt = tree_create(target, 0, sizeof(target) / sizeof(target[0]));

    recoverTree(ta);

    fail_if(!tree_equal(ta, tt));

    tree_free(ta);
    tree_free(tt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}