/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/29 上午11:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

typedef struct quad_node *quad_tree_t;
struct quad_node {
    bool val, isLeaf;
    quad_tree_t topLeft;
    quad_tree_t topRight;
    quad_tree_t bottomLeft;
    quad_tree_t bottomRight;
};

#include "0427.c"

static void quad_tree_check(quad_tree_t t, int **grid, int size) {
    const int MAXN = 0x1000;
    int front = 0, rear = 0;
    quad_tree_t queue[MAXN];

    ck_assert_ptr_nonnull(t);
    for (queue[rear++] = t; front < rear && front < size; ++front) {
        quad_tree_t now = queue[front];

        if (!now) {
            ck_assert_ptr_null(grid[front]);
            continue;
        }
        ck_assert_int_eq(grid[front][0], now->isLeaf);
        ck_assert_int_eq(grid[front][1], now->val);
        queue[rear++] = now->topLeft;
        queue[rear++] = now->topRight;
        queue[rear++] = now->bottomLeft;
        queue[rear++] = now->bottomRight;
    }
    for (int i = front; i < rear; ++i) {
        ck_assert_ptr_null(queue[i]);
    }
}
static void quad_tree_destroy(quad_tree_t t) {
    if (!t) return;
    quad_tree_destroy(t->topLeft);
    quad_tree_destroy(t->topRight);
    quad_tree_destroy(t->bottomLeft);
    quad_tree_destroy(t->bottomRight);
    free(t);
}

START_TEST(test_official_1) {
    int *grid[]   = { (int[]) { 0, 1 }, (int[]) { 1, 0 } };
    int *target[] = { (int[]) { 0, 1 }, (int[]) { 1, 0 }, (int[]) { 1, 1 }, (int[]) { 1, 1 }, (int[]) { 1, 0 } };

    quad_tree_t tree = construct(grid, LEN(grid), NULL);
    quad_tree_check(tree, target, LEN(target));
    quad_tree_destroy(tree);
}

START_TEST(test_official_2) {
    int *grid[]   = { (int[]) { 1, 1, 1, 1, 0, 0, 0, 0 }, (int[]) { 1, 1, 1, 1, 0, 0, 0, 0 },
                      (int[]) { 1, 1, 1, 1, 1, 1, 1, 1 }, (int[]) { 1, 1, 1, 1, 1, 1, 1, 1 },
                      (int[]) { 1, 1, 1, 1, 0, 0, 0, 0 }, (int[]) { 1, 1, 1, 1, 0, 0, 0, 0 },
                      (int[]) { 1, 1, 1, 1, 0, 0, 0, 0 }, (int[]) { 1, 1, 1, 1, 0, 0, 0, 0 } };
    int *target[] = { (int[]) { 0, 1 },
                      (int[]) { 1, 1 },
                      (int[]) { 0, 1 },
                      (int[]) { 1, 1 },
                      (int[]) { 1, 0 },
                      NULL,
                      NULL,
                      NULL,
                      NULL,
                      (int[]) { 1, 0 },
                      (int[]) { 1, 0 },
                      (int[]) { 1, 1 },
                      (int[]) { 1, 1 } };

    quad_tree_t tree = construct(grid, LEN(grid), NULL);
    quad_tree_check(tree, target, LEN(target));
    quad_tree_destroy(tree);
}

START_TEST(test_official_3) {
    int *grid[]   = { (int[]) { 1, 1 }, (int[]) { 1, 1 } };
    int *target[] = { (int[]) { 1, 1 } };

    quad_tree_t tree = construct(grid, LEN(grid), NULL);
    quad_tree_check(tree, target, LEN(target));
    quad_tree_destroy(tree);
}

START_TEST(test_official_4) {
    int *grid[]   = { (int[]) { 0 } };
    int *target[] = { (int[]) { 1, 0 } };

    quad_tree_t tree = construct(grid, LEN(grid), NULL);
    quad_tree_check(tree, target, LEN(target));
    quad_tree_destroy(tree);
}

START_TEST(test_official_5) {
    int *grid[]   = { (int[]) { 1, 1, 0, 0 }, (int[]) { 1, 1, 0, 0 }, (int[]) { 0, 0, 1, 1 }, (int[]) { 0, 0, 1, 1 } };
    int *target[] = { (int[]) { 0, 1 }, (int[]) { 1, 1 }, (int[]) { 1, 0 }, (int[]) { 1, 0 }, (int[]) { 1, 1 } };

    quad_tree_t tree = construct(grid, LEN(grid), NULL);
    quad_tree_check(tree, target, LEN(target));
    quad_tree_destroy(tree);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}