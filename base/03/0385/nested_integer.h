/**
 * nested_integer.h
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/15 上午8:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#pragma once

typedef struct NestedInteger nested_int_t;

void nested_free(nested_int_t *);

//////////////////////////////////////////////
// Initializes an empty nested list and return a reference to the nested integer.
nested_int_t *NestedIntegerInit();

// Return true if this NestedInteger holds a single integer, rather than a nested list.
bool NestedIntegerIsInteger(nested_int_t *);

// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
int NestedIntegerGetInteger(nested_int_t *);

// Set this NestedInteger to hold a single integer.
void NestedIntegerSetInteger(nested_int_t *, int);

// Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
void NestedIntegerAdd(nested_int_t *, nested_int_t *);

// Return the nested list that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
nested_int_t **NestedIntegerGetList(nested_int_t *);

// Return the nested list's size that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
int NestedIntegerGetListSize(nested_int_t *);