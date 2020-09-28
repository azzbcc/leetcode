/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/28 下午2:10
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
bool node_equal(node_t t1, node_t t2) {
    if (t1 == t2) return true;
    if (!t1 || !t2) return false;

    return t1->val == t2->val && node_equal(t1->next, t2->next) && node_equal(t1->left, t2->left)
           && node_equal(t1->right, t2->right);
}

#include "0117.c"

START_TEST(test_official) {
    node_t ta, target, ans;
    int arr[] = { 1, 2, 3, 4, 5, null, 7 };

    ta     = node_create(arr, 0, sizeof(arr) / sizeof(arr[0]));
    target = node_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    node_find(target, 2)->next = node_find(target, 3);
    node_find(target, 4)->next = node_find(target, 5);
    node_find(target, 5)->next = node_find(target, 7);

    ans = connect(ta);

    ck_assert(node_equal(ans, target));

    node_free(ta);
    node_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}