/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/7 下午6:38
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

#include "0019.c"

START_TEST(test_official) {
    int input = 2, arr1[] = { 1, 2, 3, 4, 5 }, arr2[] = { 1, 2, 3, 5 };
    link_list_t l1 = list_create(arr1, sizeof(arr1) / sizeof(arr1[0]));
    link_list_t l2 = list_create(arr2, sizeof(arr2) / sizeof(arr2[0]));

    link_list_t l3 = removeNthFromEnd(l1, input);

    fail_if(!list_equal(l2, l3));

    list_free(l2);
    list_free(l3);
}

START_TEST(test_failed) {
    int input = 1, arr1[] = { 1 }, arr2[] = {};
    link_list_t l1 = list_create(arr1, sizeof(arr1) / sizeof(arr1[0]));
    link_list_t l2 = list_create(arr2, sizeof(arr2) / sizeof(arr2[0]));

    link_list_t l3 = removeNthFromEnd(l1, input);

    fail_if(!list_equal(l2, l3));

    list_free(l2);
    list_free(l3);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}