/**
 * tree.h
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/20 下午4:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H

#include <common.h>

#define null INT32_MIN

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} * tree_t;
tree_t tree_create(const int *, size_t, size_t);
void tree_free(tree_t);
bool tree_equal(tree_t, tree_t);

#endif // LEETCODE_TREE_H
