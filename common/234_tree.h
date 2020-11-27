/**
 * 234_tree.h
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/27 下午3:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#ifndef LEETCODE_234_TREE_H
#define LEETCODE_234_TREE_H

#include <common.h>

typedef struct _234_TreeNode {
    int count, val[3];
    struct _234_TreeNode *parent;
    struct _234_TreeNode *children[4];
} * _234_tree_t;
#define _234_tree_create(array) _234_tree_create_size(array, LEN(array))
_234_tree_t _234_tree_create_size(const int *, size_t);
bool _234_tree_add(_234_tree_t *, int);
bool _234_tree_del(_234_tree_t *, int);
void _234_tree_free(_234_tree_t);
bool _234_tree_equal(_234_tree_t, _234_tree_t);
_234_tree_t _234_tree_find(_234_tree_t, int);
void _234_tree_print(_234_tree_t);

#endif // LEETCODE_234_TREE_H
