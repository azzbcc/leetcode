/**
 * avl_tree.h
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/10 下午2:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#ifndef LEETCODE_AVL_TREE_H
#define LEETCODE_AVL_TREE_H

#include <common.h>

typedef struct AVLTreeNode {
    int val;
    int height;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
} * avl_tree_t;
#define avl_tree_create(array) avl_tree_create_size(array, LEN(array))
avl_tree_t avl_tree_create_size(const int *, size_t);
bool avl_tree_add(avl_tree_t *, int);
bool avl_tree_del(avl_tree_t *, int);
int avl_tree_height(avl_tree_t);
void avl_tree_free(avl_tree_t);
bool avl_tree_equal(avl_tree_t, avl_tree_t);
avl_tree_t avl_tree_find(avl_tree_t, int);

#endif // LEETCODE_AVL_TREE_H
