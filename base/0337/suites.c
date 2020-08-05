/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/5 上午11:34
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

#include "0337.c"

START_TEST(test_official_1) {
    int arr[] = { 3, 2, 3, null, 3, null, 1 };
    tree_t ta = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    int target = 7, ans = rob(ta);
    ck_assert_msg(target == ans, "error, except %d but got %d on rob().", target, ans);

    tree_free(ta);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 4, 5, 1, 3, null, 1 };
    tree_t ta = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    int target = 9, ans = rob(ta);
    ck_assert_msg(target == ans, "error, except %d but got %d on rob().", target, ans);

    tree_free(ta);
}

START_TEST(test_own) {
    int arr[] = { 1, 1, 2, 3 };
    tree_t ta = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    int target = 5, ans = rob(ta);
    ck_assert_msg(target == ans, "error, except %d but got %d on rob().", target, ans);

    tree_free(ta);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}