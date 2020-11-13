/**
 * 23_tree.h
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/14 下午3:57
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#ifndef LEETCODE_23_TREE_H
#define LEETCODE_23_TREE_H

#include <common.h>

typedef struct _23_TreeNode {
    int count, val[2];
    struct _23_TreeNode *parent;
    struct _23_TreeNode *children[3];
} * _23_tree_t;
#define _23_tree_create(array) _23_tree_create_size(array, LEN(array))
_23_tree_t _23_tree_create_size(const int *, size_t);
bool _23_tree_add(_23_tree_t *, int);
bool _23_tree_del(_23_tree_t *, int);
void _23_tree_free(_23_tree_t);
bool _23_tree_equal(_23_tree_t, _23_tree_t);
_23_tree_t _23_tree_find(_23_tree_t, int);
void _23_tree_print(_23_tree_t);

#endif // LEETCODE_23_TREE_H
