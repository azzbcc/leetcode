/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/10 下午2:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

typedef struct Node {
    int val;
    int numChildren;
    struct Node** children;
}* node_t;

#include "0589.c"

#define null INT32_MIN

static node_t node_create(int* arr, size_t size) {
    if (!size) return NULL;
    node_t nodes[size];

    for (int i = 0; i < size; ++i) {
        nodes[i] = arr[i] == null ? NULL : calloc(1, sizeof(struct Node));
        if (nodes[i]) nodes[i]->val = arr[i];
    }
    for (int l = 2, r, p = 0; l < size; l = r + 1) {
        for (r = l; r < size && nodes[r]; ++r) {}
        nodes[p]->children = malloc((nodes[p]->numChildren = r - l) * sizeof(node_t));
        memcpy(nodes[p]->children, nodes + l, nodes[p]->numChildren * sizeof(node_t));
        for (++p; p < size && !nodes[p]; ++p) {}
    }
    return nodes[0];
}
static void node_free(node_t tree) {
    if (!tree) return;
    for (int i = 0; i < tree->numChildren; ++i) {
        node_free(tree->children[i]);
    }
    if (tree->children) free(tree->children);
    free(tree);
}

START_TEST(test_official_1) {
    int arr[] = { 1, null, 3, 2, 4, null, 5, 6 }, target[] = { 1, 3, 5, 6, 2, 4 };
    node_t tree = node_create(arr, LEN(arr));
    int len, *ans = preorder(tree, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
    node_free(tree);
}

START_TEST(test_official_2) {
    int arr[]    = { 1, null, 2,    3,    4,  5,    null, null, 6,  7,    null, 8, null,
                     9, 10,   null, null, 11, null, 12,   null, 13, null, null, 14 };
    int target[] = { 1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10 };
    node_t tree  = node_create(arr, LEN(arr));
    int len, *ans = preorder(tree, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
    node_free(tree);
}

START_TEST(test_failed) {
    int arr[] = {}, target[] = {};
    node_t tree = node_create(arr, LEN(arr));
    int len, *ans = preorder(tree, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
    node_free(tree);
}

START_TEST(test_own) {
    int max_len = 10000, arr[max_len + 1];
    memset(arr, 0, sizeof(arr));
    node_t tree = node_create(arr, LEN(arr));
    int len, *ans = preorder(tree, &len);
    ck_assert_int_eq(len, max_len);
    ck_assert_mem_eq(ans, arr, len * sizeof(int));
    free(ans);
    node_free(tree);
}

void tcase_complete(TCase* t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}