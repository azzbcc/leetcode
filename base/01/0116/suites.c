/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/15 上午11:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#define null INT32_MIN

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
} * node_t;

node_t node_create(const int *data, size_t cur, size_t len) {
    if (len <= cur || data[cur] == null) return NULL;
    node_t t = calloc(1, sizeof(struct Node));
    t->val   = data[cur];
    t->left  = node_create(data, 2 * cur + 1, len);
    t->right = node_create(data, 2 * cur + 2, len);

    return t;
}
void node_free(node_t t) {
    if (t->left) node_free(t->left);
    if (t->right) node_free(t->right);
    free(t);
}
node_t node_find(node_t root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    node_t left = node_find(root->left, val);
    if (left) return left;
    return node_find(root->right, val);
}
bool node_list_equal(node_t l1, node_t l2) {
    if (l1 == l2) return true;
    if (!l1 || !l2) return false;

    return l1->val == l2->val && node_list_equal(l1->next, l2->next);
}
bool node_equal(node_t t1, node_t t2) {
    while (t1 && t2) {
        if (!node_list_equal(t1, t2)) return false;
        t1 = t1->left, t2 = t2->left;
    }
    return !t1 && !t2;
}

#include "0116.c"

START_TEST(test_official) {
    node_t ta, target, ans;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };

    ta     = node_create(arr, 0, sizeof(arr) / sizeof(arr[0]));
    target = node_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    node_find(target, 2)->next = node_find(target, 3);
    node_find(target, 4)->next = node_find(target, 5);
    node_find(target, 5)->next = node_find(target, 6);
    node_find(target, 6)->next = node_find(target, 7);

    ans = connect(ta);

    ck_assert(node_equal(ans, target));

    node_free(ta);
    node_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}