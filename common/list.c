/**
 * list.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/20 下午4:22
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <list.h>
#include <print.h>

list_t list_create_size(const int *num, size_t len) {
    list_t head = NULL, tail = NULL;

    for (size_t i = 0; i < len; ++i) {
        // init list node
        list_t tmp = calloc(1, sizeof(struct ListNode));
        tmp->val   = num[i];
        tmp->next  = NULL;

        // add node to link
        if (head == NULL) {
            head = tmp;
        } else {
            tail->next = tmp;
        }

        // change link tail
        tail = tmp;
    }

    return head;
}

void list_free(list_t l) {
    if (l) {
        list_free(l->next);
        free(l);
    }
}

bool list_equal(list_t l1, list_t l2) {
    if (l1 == l2) return true;
    if (!l1 || !l2) return false;

    return l1->val == l2->val && list_equal(l1->next, l2->next);
}

list_t list_index(list_t l, size_t index) {
    for (; l && index; index--, l = l->next) {}
    return l;
}

list_t list_find(list_t l, int val) {
    for (; l && l->val != val; l = l->next) {}
    return l;
}

static void list_node_print(void *list) {
    list_t l = list;
    printf("%d", l->val);
}
void list_print(list_t l) {
    int offsets[] = { offsetof(struct ListNode, next) };
    print_static_tree(l, offsets, LEN(offsets), 0x1000, list_node_print);
}