/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/10 上午11:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} * link_list_t;

link_list_t list_create(const int *num, int len) {
    link_list_t head = NULL, tail = NULL;

    for (int i = 0; i < len; ++i) {
        // init list node
        link_list_t tmp = calloc(1, sizeof(struct ListNode));
        tmp->val        = num[i];
        tmp->next       = NULL;

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

void list_free(link_list_t l) {
    if (l) {
        list_free(l->next);
        free(l);
    }
}

bool list_equal(link_list_t l1, link_list_t l2) {
    if (l1 == l2) return true;
    if (!l1 || !l2) return false;

    return l1->val == l2->val && list_equal(l1->next, l2->next);
}

#include "0023.c"

START_TEST(test_official) {
    int arr[][4]     = { { 3, 1, 4, 5 }, { 3, 1, 3, 4 }, { 2, 2, 6 } };
    int arr_target[] = { 1, 1, 2, 3, 4, 4, 5, 6 };

    link_list_t lists[3] = { NULL };
    for (int i = 0; i < sizeof(lists) / sizeof(lists[0]); ++i) {
        lists[i] = list_create(arr[i] + 1, arr[i][0]);
    }
    link_list_t target = list_create(arr_target, sizeof(arr_target) / sizeof(arr_target[0]));
    link_list_t ans    = mergeKLists(lists, sizeof(lists) / sizeof(lists[0]));

    fail_if(!list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}