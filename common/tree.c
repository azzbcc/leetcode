/**
 * tree.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/20 下午4:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <tree.h>

tree_t tree_create(const int *data, size_t cur, size_t len) {
    if (len <= cur || data[cur] == null) return NULL;

    tree_t t = calloc(1, sizeof(struct TreeNode));
    t->val   = data[cur];
    t->left  = tree_create(data, 2 * cur + 1, len);
    t->right = tree_create(data, 2 * cur + 2, len);

    return t;
}

void tree_free(tree_t t) {
    if (t->left) tree_free(t->left);
    if (t->right) tree_free(t->right);
    free(t);
}

bool tree_equal(tree_t t1, tree_t t2) {
    if (t1 == t2) return true;
    if (!t1 || !t2) return false;

    return t1->val == t2->val && tree_equal(t1->left, t2->left) && tree_equal(t1->right, t2->right);
}