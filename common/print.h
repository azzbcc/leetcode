/**
 * print.h
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/12 下午12:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#ifndef LEETCODE_PRINT_H
#define LEETCODE_PRINT_H

#include <common.h>

void print_static_tree(void *, int[], int, int, void (*)(void *));
void print_dynamic_tree(void *, int, int, int, void (*)(void *));

#endif // LEETCODE_PRINT_H
