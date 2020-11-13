/**
 * rb_tree.h
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/17 下午3:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#ifndef LEETCODE_RB_TREE_H
#define LEETCODE_RB_TREE_H

#include <common.h>

typedef enum { BLACK = 0, RED = 1 } rb_tree_color_t;
typedef struct RBTreeNode {
    int val;
    rb_tree_color_t color;
    struct RBTreeNode *left;
    struct RBTreeNode *right;
    struct RBTreeNode *parent;
} * rb_tree_t;
#define rb_tree_create(array) rb_tree_create_size(array, LEN(array))
rb_tree_t rb_tree_create_size(const int *, size_t);
bool rb_tree_add(rb_tree_t *, int);
bool rb_tree_del(rb_tree_t *, int);
rb_tree_color_t rb_tree_color(rb_tree_t);
void rb_tree_free(rb_tree_t);
bool rb_tree_equal(rb_tree_t, rb_tree_t);
rb_tree_t rb_tree_find(rb_tree_t, int);
void rb_tree_print(rb_tree_t);

#endif // LEETCODE_RB_TREE_H
