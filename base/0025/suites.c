/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/10 下午4:12
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

#include "0025.c"

START_TEST(test_official_1) {
    int arr[]        = { 1, 2, 3, 4, 5 };
    int arr_target[] = { 2, 1, 4, 3, 5 };

    link_list_t l      = list_create(arr, sizeof(arr) / sizeof(arr[0]));
    link_list_t target = list_create(arr_target, sizeof(arr_target) / sizeof(arr_target[0]));
    link_list_t ans    = reverseKGroup(l, 2);

    fail_if(!list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

START_TEST(test_official_2) {
    int arr[]        = { 1, 2, 3, 4, 5 };
    int arr_target[] = { 3, 2, 1, 4, 5 };

    link_list_t l      = list_create(arr, sizeof(arr) / sizeof(arr[0]));
    link_list_t target = list_create(arr_target, sizeof(arr_target) / sizeof(arr_target[0]));
    link_list_t ans    = reverseKGroup(l, 3);

    fail_if(!list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

START_TEST(test_failed) {
    int arr[]        = { 1, 2 };
    int arr_target[] = { 2, 1 };

    link_list_t l      = list_create(arr, sizeof(arr) / sizeof(arr[0]));
    link_list_t target = list_create(arr_target, sizeof(arr_target) / sizeof(arr_target[0]));
    link_list_t ans    = reverseKGroup(l, 2);

    fail_if(!list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}