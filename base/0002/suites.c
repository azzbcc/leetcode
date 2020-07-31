/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 20-7-24 下午17:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} * link_list_t;

link_list_t list_create(int num) {
    link_list_t head = NULL, tail = NULL;

    for (; num > 0; num /= 10) {
        // init list node
        link_list_t tmp = calloc(1, sizeof(struct ListNode));
        tmp->val        = num % 10;
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

int list_val(link_list_t l) {
    if (!l) return 0;
    return list_val(l->next) * 10 + l->val;
}

void list_free(link_list_t l) {
    if (l) {
        list_free(l->next);
        free(l);
    }
}

#include "0002.c"

START_TEST(test_official) {
    link_list_t l1 = list_create(342);
    link_list_t l2 = list_create(465);
    int sum        = list_val(l1) + list_val(l2);

    link_list_t l3 = addTwoNumbers(l1, l2);
    ck_assert_msg(list_val(l3) == sum, "error, except %d but got %d on addTwoNumbers(243, 564).", sum, list_val(l3));

    list_free(l1);
    list_free(l2);
    list_free(l3);
}

START_TEST(test_own) {
    link_list_t l1 = list_create(9543);
    link_list_t l2 = list_create(564);
    int sum        = list_val(l1) + list_val(l2);

    link_list_t l3 = addTwoNumbers(l1, l2);
    ck_assert_msg(list_val(l3) == sum, "error, except %d but got %d on addTwoNumbers(243, 564).", sum, list_val(l3));

    list_free(l1);
    list_free(l2);
    list_free(l3);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
    tcase_add_test(t, test_own);
}