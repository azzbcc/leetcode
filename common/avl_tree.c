/**
 * avl_tree.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/10 下午2:37
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <avl_tree.h>
#include <print.h>

static int max(int a, int b) {
    return a > b ? a : b;
}

static avl_tree_t avl_tree_node_new(int val) {
    avl_tree_t tree = calloc(1, sizeof(struct AVLTreeNode));
    tree->val = val, tree->height = 1;
    return tree;
}

static void avl_tree_update_height(avl_tree_t t) {
    t->height = max(avl_tree_height(t->left), avl_tree_height(t->right)) + 1;
}

static void avl_tree_left_rotate(avl_tree_t *tree) {
    avl_tree_t t = *tree, child = t->right;
    *tree = child, t->right = child->left, child->left = t;
    avl_tree_update_height(t);
}

static void avl_tree_right_rotate(avl_tree_t *tree) {
    avl_tree_t t = *tree, child = t->left;
    *tree = child, t->left = child->right, child->right = t;
    avl_tree_update_height(t);
}

static void avl_tree_balance(avl_tree_t *tree) {
    avl_tree_t t = *tree;
    int balance  = avl_tree_height(t->left) - avl_tree_height(t->right);
    if (balance < -1) {
        if (avl_tree_height(t->right->left) > avl_tree_height(t->right->right)) {
            avl_tree_right_rotate(&t->right);
            avl_tree_update_height(t->right);
        }
        avl_tree_left_rotate(tree);
    } else if (balance > 1) {
        if (avl_tree_height(t->left->right) > avl_tree_height(t->left->left)) {
            avl_tree_left_rotate(&t->left);
            avl_tree_update_height(t->left);
        }
        avl_tree_right_rotate(tree);
    } else {
        avl_tree_update_height(*tree);
    }
}

avl_tree_t avl_tree_create_size(const int arr[], size_t len) {
    if (!len) return NULL;
    size_t mid = len / 2;

    avl_tree_t t = avl_tree_node_new(arr[mid]);
    if (mid) t->left = avl_tree_create_size(arr, mid);
    if (mid + 1 < len) t->right = avl_tree_create_size(arr + mid + 1, len - mid - 1);
    avl_tree_update_height(t);

    return t;
}

bool avl_tree_add(avl_tree_t *tree, int val) {
    avl_tree_t t = *tree;
    if (!t) {
        *tree = avl_tree_node_new(val);
        return true;
    }
    if (val == t->val || !avl_tree_add(val < t->val ? &t->left : &t->right, val)) return false;

    avl_tree_balance(tree);

    return true;
}

bool avl_tree_del(avl_tree_t *tree, int val) {
    avl_tree_t t = *tree;
    if (!t) return false;
    if (t->val == val) {
        if (t->left && t->right) {
            bool right     = avl_tree_height(t->left) < avl_tree_height(t->right);
            avl_tree_t cur = right ? t->right : t->left;
            for (; right ? cur->left : cur->right; cur = right ? cur->left : cur->right) {}
            t->val = cur->val, cur->val = val;
            return avl_tree_del(tree, val);
        }
        *tree = t->left ? t->left : t->right;
        free(t);
        return true;
    }
    if (!avl_tree_del(val < t->val ? &t->left : &t->right, val)) return false;

    avl_tree_balance(tree);

    return true;
}

int avl_tree_height(avl_tree_t t) {
    return t ? t->height : 0;
}

void avl_tree_free(avl_tree_t t) {
    if (t->left) avl_tree_free(t->left);
    if (t->right) avl_tree_free(t->right);
    free(t);
}

bool avl_tree_equal(avl_tree_t t1, avl_tree_t t2) {
    if (t1 == t2) return true;
    if (!t1 || !t2) return false;

    return t1->val == t2->val && avl_tree_equal(t1->left, t2->left) && avl_tree_equal(t1->right, t2->right);
}

avl_tree_t avl_tree_find(avl_tree_t t, int val) {
    if (!t || t->val == val) return t;
    return avl_tree_find(val < t->val ? t->left : t->right, val);
}

static void avl_tree_node_print(void *tree) {
    avl_tree_t t = tree;
    printf("[%d, %d]", t->val, t->height);
}
void avl_tree_print(avl_tree_t t) {
    int offsets[] = { offsetof(struct AVLTreeNode, left), offsetof(struct AVLTreeNode, right) };
    print_static_tree(t, offsets, LEN(offsets), avl_tree_height(t), avl_tree_node_print);
}