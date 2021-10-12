/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/12 下午5:28
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <print.h>

typedef struct Node {
    int val;
    int numChildren;
    struct Node** children;
} * node_t;

#include "0559.c"

#define null INT32_MIN

static node_t node_create(int arr[], size_t size) {
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
    int arr[]   = { 1, null, 3, 2, 4, null, 5, 6 };
    node_t tree = node_create(arr, LEN(arr));

    int target = 3, ans = maxDepth(tree);
    ck_assert_int_eq(ans, target);

    node_free(tree);
}

START_TEST(test_official_2) {
    int arr[]   = { 1, null, 2,    3,    4,  5,    null, null, 6,  7,    null, 8, null,
                  9, 10,   null, null, 11, null, 12,   null, 13, null, null, 14 };
    node_t tree = node_create(arr, LEN(arr));

    int target = 5, ans = maxDepth(tree);
    ck_assert_int_eq(ans, target);

    node_free(tree);
}

void tcase_complete(TCase* t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}