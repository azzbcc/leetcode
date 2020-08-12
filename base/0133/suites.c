/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/12 上午11:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
} * node_t;

static int cmp(const void *a, const void *b) {
    struct Node *pa = *( struct Node ** )a;
    struct Node *pb = *( struct Node ** )b;

    return pa->val - pb->val;
}
node_t node_create(int arr[][SIZE], int len) {
    node_t nodes[SIZE] = { NULL };
    for (int i = 0; i < len; ++i) {
        nodes[i] = calloc(1, sizeof(struct Node));
    }

    for (int i = 0; i < len; ++i) {
        int num = 0;
        while (arr[i][num]) {
            num += 1;
        }

        nodes[i]->val          = i + 1;
        nodes[i]->numNeighbors = num;
        nodes[i]->neighbors    = calloc(num, sizeof(struct Node*));
        for (int j = 0; j < num; ++j) {
            nodes[i]->neighbors[j] = nodes[arr[i][j] - 1];
        }
    }

    return nodes[0];
}

void node_free(node_t n) {
    if (!n) return;

    int count              = 1;
    node_t nodes[SIZE]     = { n };
    bool visited[SIZE + 1] = { false, true };

    for (int i = 0; i < count; ++i) {
        node_t now = nodes[i];
        for (int j = 0; j < now->numNeighbors; ++j) {
            node_t next = now->neighbors[j];
            if (!visited[next->val]) {
                visited[next->val] = true;
                nodes[count++]     = next;
            }
        }
    }
    for (int i = 0; i < count; ++i) {
        free(nodes[i]->neighbors);
        free(nodes[i]);
    }
}

bool node_equal(node_t a, node_t b) {
    if (a == b) return true;
    if (!a || !b) return false;

    int count_a = 1, count_b = 1;
    bool visited[SIZE + 1] = {};
    node_t nodes_a[SIZE] = { a }, nodes_b[SIZE] = { b };

    memset(visited, 0, sizeof(visited));
    visited[a->val] = true;
    for (int i = 0; i < count_a; ++i) {
        node_t now = nodes_a[i];
        for (int j = 0; j < now->numNeighbors; ++j) {
            node_t next = now->neighbors[j];
            if (!visited[next->val]) {
                visited[next->val] = true;
                nodes_a[count_a++] = next;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    visited[b->val] = true;
    for (int i = 0; i < count_b; ++i) {
        node_t now = nodes_b[i];
        for (int j = 0; j < now->numNeighbors; ++j) {
            node_t next = now->neighbors[j];
            if (!visited[next->val]) {
                visited[next->val] = true;
                nodes_b[count_b++] = next;
            }
        }
    }
    if (count_a != count_b) return false;
    qsort(nodes_a, count_a, sizeof(struct Node *), cmp);
    qsort(nodes_b, count_b, sizeof(struct Node *), cmp);

    for (int i = 0; i < count_a; ++i) {
        node_t pa = nodes_a[i], pb = nodes_b[i];
        if (!pa || !pb) return false;
        if (pa->numNeighbors != pb->numNeighbors) return false;
        qsort(pa->neighbors, pa->numNeighbors, sizeof(struct Node *), cmp);
        qsort(pb->neighbors, pb->numNeighbors, sizeof(struct Node *), cmp);
        for (int j = 0; j < pa->numNeighbors; ++j) {
            if (pa->neighbors[j]->val != pb->neighbors[j]->val) {
                return false;
            }
        }
    }
    return true;
}

#include "0133.c"

START_TEST(test_official_1) {
    int arr[][SIZE] = { { 2, 4 }, { 1, 3 }, { 2, 4 }, { 1, 3 } };

    node_t n   = node_create(arr, sizeof(arr) / sizeof(arr[0]));
    node_t ans = cloneGraph(n);

    fail_if(!node_equal(n, ans));

    node_free(n);
    node_free(ans);
}

void tcase_complete(TCase* t) {
    tcase_add_test(t, test_official_1);
}
