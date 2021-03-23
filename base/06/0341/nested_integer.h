/**
 * nested_integer.h
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/23 下午2:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#ifndef LEETCODE_NESTED_INTEGER_H
#define LEETCODE_NESTED_INTEGER_H

typedef struct NestedInteger nested_int_t;

// Return true if this NestedInteger holds a single integer, rather than a nested list.
bool NestedIntegerIsInteger(nested_int_t *);

// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
int NestedIntegerGetInteger(nested_int_t *);

// Return the nested list that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
nested_int_t **NestedIntegerGetList(nested_int_t *);

// Return the nested list's size that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
int NestedIntegerGetListSize(nested_int_t *);

#endif // LEETCODE_NESTED_INTEGER_H
