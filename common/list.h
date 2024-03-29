/**
 * list.h
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/20 下午4:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#ifndef LEETCODE_LIST_H
#define LEETCODE_LIST_H

#include <common.h>

// list
typedef struct ListNode {
    int val;
    struct ListNode *next;
} *list_t;
#define list_create(array) list_create_size(array, LEN(array))
list_t list_create_size(const int *, size_t);
void list_free(list_t);
bool list_equal(list_t, list_t);
list_t list_index(list_t, size_t);
list_t list_find(list_t, int);
void list_print(list_t);

#endif // LEETCODE_LIST_H
