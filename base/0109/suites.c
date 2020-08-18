/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/18 上午11:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define null INT32_MIN

typedef struct ListNode {
    int val;
    struct ListNode *next;
} * link_list_t;
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} * tree_t;

link_list_t list_create(const int *num, int len) {
    link_list_t head = NULL, tail = NULL;

    for (int i = 0; i < len; ++i) {
        // init list node
        link_list_t tmp = calloc(1, sizeof(struct ListNode));
        tmp->val        = num[i];
        tmp->next       = NULL;

        // add node to link
        if (head == NULL) {
            head = tmp;
        } else {
            tail->next = tmp;
        }

        // change link tail
        tail = tmp;
    }

    return head;
}

void list_free(link_list_t l) {
    if (l) {
        list_free(l->next);
        free(l);
    }
}

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

#include "0109.c"

START_TEST(test_official) {
    int arr1[] = { -10, -3, 0, 5, 9 };
    int arr2[] = { 0, -3, 9, -10, null, 5 };

    link_list_t l = list_create(arr1, sizeof(arr1) / sizeof(arr1[0]));
    tree_t target = tree_create(arr2, 0, sizeof(arr2) / sizeof(arr2[0]));

    tree_t ans = sortedListToBST(l);

    fail_if(!tree_equal(target, ans));

    list_free(l);
    tree_free(ans);
    tree_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}