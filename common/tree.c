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
#include <print.h>

static tree_t tree_node_new(int val) {
    if (val == null) return NULL;
    tree_t t = calloc(1, sizeof(struct TreeNode));
    t->val = val, t->left = t->right = NULL;
    return t;
}
tree_t tree_create_size(const int *data, size_t len) {
    if (len == 0) return NULL;
    tree_t t = tree_node_new(data[0]), nodes[2][0x1000] = { t };
    for (int di = 1, ni = 0, nlen = 1, now = 0; di < len && nlen; now = 1 - now, nlen = ni, ni = 0) {
        for (int i = 0; i < nlen; ++i) {
            if (di < len) nodes[now][i]->left = tree_node_new(data[di++]);
            if (di < len) nodes[now][i]->right = tree_node_new(data[di++]);
            if (nodes[now][i]->left) nodes[1 - now][ni++] = nodes[now][i]->left;
            if (nodes[now][i]->right) nodes[1 - now][ni++] = nodes[now][i]->right;
        }
    }
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

tree_t tree_find(tree_t root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    tree_t left = tree_find(root->left, val);
    if (left) return left;
    return tree_find(root->right, val);
}

static void tree_node_print(void *tree) {
    tree_t t = tree;
    printf("%d", t->val);
}
void tree_print(tree_t root) {
    int offsets[] = { offsetof(struct TreeNode, left), offsetof(struct TreeNode, right) };
    print_static_tree(root, offsets, LEN(offsets), 0x1000, tree_node_print);
}