/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/7 上午00:16
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

#include "0100.c"

START_TEST(test_official_1) {
    int arr1[] = { 1, 2, 3 }, arr2[] = { 1, 2, 3 };

    tree_t t1 = tree_create(arr1, 0, sizeof(arr1) / sizeof(arr1[0]));
    tree_t t2 = tree_create(arr2, 0, sizeof(arr2) / sizeof(arr2[0]));

    bool target = true, ans = isSameTree(t1, t2);

    fail_if(target != ans);

    tree_free(t1);
    tree_free(t2);
}

START_TEST(test_official_2) {
    int arr1[] = { 1, 2 }, arr2[] = { 1, null, 2 };

    tree_t t1 = tree_create(arr1, 0, sizeof(arr1) / sizeof(arr1[0]));
    tree_t t2 = tree_create(arr2, 0, sizeof(arr2) / sizeof(arr2[0]));

    bool target = false, ans = isSameTree(t1, t2);

    fail_if(target != ans);

    tree_free(t1);
    tree_free(t2);
}

START_TEST(test_official_3) {
    int arr1[] = { 1, 2, 1 }, arr2[] = { 1, 1, 2 };

    tree_t t1 = tree_create(arr1, 0, sizeof(arr1) / sizeof(arr1[0]));
    tree_t t2 = tree_create(arr2, 0, sizeof(arr2) / sizeof(arr2[0]));

    bool target = false, ans = isSameTree(t1, t2);

    fail_if(target != ans);

    tree_free(t1);
    tree_free(t2);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}