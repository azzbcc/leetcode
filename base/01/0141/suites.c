/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/29 00:22
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} node_t;

#include "0141.c"

static void valid(int *arr, size_t len, int pos) {
    node_t nodes[len + 1];

    memset(nodes, 0, sizeof(nodes));
    for (int i = 0; i < len; ++i) {
        nodes[i] = (node_t) { arr[i], &nodes[i + 1] };
    }
    if (pos > -1) nodes[len - 1].next = &nodes[pos];
    ck_assert_int_eq(pos > -1, hasCycle(nodes));
}

START_TEST(test_official_1) {
    int arr[] = { 3, 2, 0, -4 }, pos = 1;
    valid(arr, LEN(arr), pos);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2 }, pos = 0;
    valid(arr, LEN(arr), pos);
}

START_TEST(test_official_3) {
    int arr[] = { 1 }, pos = -1;
    valid(arr, LEN(arr), pos);
}

START_TEST(test_failed) {
    int arr[] = {}, pos = -1;
    valid(arr, LEN(arr), pos);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}