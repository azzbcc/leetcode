/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/24 上午11:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
    struct Node *child;
} * node_t;

#include "0430.c"

#define null INT32_MIN

static node_t node_create(int arr[], size_t len) {
    node_t nodes[len];
    memset(nodes, 0, sizeof(nodes));
    for (int i = 0, p = 0, skip = 0; i < len; ++i) {
        if (arr[i] == null) {
            skip++;
            continue;
        }
        nodes[i]      = malloc(sizeof(*nodes[i]));
        nodes[i]->val = arr[i], nodes[i]->prev = nodes[i]->next = nodes[i]->child = NULL;
        if (i && nodes[i - 1]) nodes[i]->prev = nodes[i - 1], nodes[i - 1]->next = nodes[i];
        if (skip > 0) p += skip - 1, nodes[p]->child = nodes[i], p = i, skip = 0;
    }
    return nodes[0];
}
static void node_free(node_t node) {
    if (!node) return;
    node_free(node->next);
    node_free(node->child);
    free(node);
}
static bool node_equal(node_t n1, node_t n2) {
    if (n1 == n2) return true;
    if (!n1 || !n2) return false;
    if ((n1->prev == NULL) + (n2->prev == NULL) == 1) return false;
    if (n1->prev && n1->prev->val != n2->prev->val) return false;
    return n1->val == n2->val && node_equal(n1->next, n2->next) && node_equal(n1->child, n2->child);
}

START_TEST(test_official_1) {
    int arr[]    = { 1, 2, 3, 4, 5, 6, null, null, null, 7, 8, 9, 10, null, null, 11, 12 };
    int target[] = { 1, 2, 3, 7, 8, 11, 12, 9, 10, 4, 5, 6 };

    node_t t  = node_create(arr, LEN(arr));
    node_t tt = node_create(target, LEN(target));

    node_t ta = flatten(t);

    ck_assert(node_equal(ta, tt));

    node_free(ta);
    node_free(tt);
}

START_TEST(test_official_2) {
    int arr[]    = { 1, 2, null, 3 };
    int target[] = { 1, 3, 2 };

    node_t t  = node_create(arr, LEN(arr));
    node_t tt = node_create(target, LEN(target));

    node_t ta = flatten(t);

    ck_assert(node_equal(ta, tt));

    node_free(ta);
    node_free(tt);
}

START_TEST(test_official_3) {
    node_t ans = flatten(NULL);
    ck_assert_ptr_null(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}