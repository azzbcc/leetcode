/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/17 下午2:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0220.c"

static void rb_tree_check(rb_tree_t t) {
    if (!t) return;

    const int MAXN = 0x1000;
    int front = 0, rear = 0, black_count = -1;
    struct node {
        rb_tree_t tree;
        int count;
    } queue[MAXN];

    ck_assert_int_eq(false, rb_tree_red(t));
    ck_assert_ptr_eq(t->p[2], NULL);
    queue[rear++] = (struct node) { t, 1 };
    while (front < rear) {
        struct node now = queue[front];
        front           = (front + 1) % MAXN;

        if (rb_tree_red(now.tree)) {
            ck_assert_int_eq(false, rb_tree_red(now.tree->p[0]));
            ck_assert_int_eq(false, rb_tree_red(now.tree->p[1]));
        }
        if (!now.tree) {
            if (black_count < 0) black_count = now.count;
            ck_assert_int_eq(black_count, now.count);
        } else {
            queue[rear] = (struct node) { now.tree->p[0], now.count + !rb_tree_red(now.tree->p[0]) };
            rear        = (rear + 1) % MAXN;
            queue[rear] = (struct node) { now.tree->p[1], now.count + !rb_tree_red(now.tree->p[1]) };
            rear        = (rear + 1) % MAXN;
        }
    }
}
START_TEST(test_rb_tree) {
    int pos           = 0;
    rb_tree_t t       = NULL;
    node_t nodes[300] = { { 30, true } };

    rb_tree_add(&t, &nodes[pos++]);
    rb_tree_check(t);

    for (int i = 1; i <= 20; ++i) {
        nodes[pos] = (node_t) { 30 + i, true };
        rb_tree_add(&t, &nodes[pos++]);
        rb_tree_check(t);
    }
    for (int i = 1; i <= 20; ++i) {
        nodes[pos] = (node_t) { 30 - i, true };
        rb_tree_add(&t, &nodes[pos++]);
        rb_tree_check(t);
    }
    for (int i = 0; i < 200; ++i) {
        nodes[pos] = (node_t) { rand() % 100, true };
        rb_tree_add(&t, &nodes[pos++]);
        rb_tree_check(t);
    }

    while (t) {
        rb_tree_del(&t, rand() % 100);
        rb_tree_check(t);
    }
}

START_TEST(test_official_1) {
    int nums[] = { 1, 2, 3, 1 }, k = 3, t = 0;
    bool target = true, ans = containsNearbyAlmostDuplicate(nums, LEN(nums), k, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 0, 1, 1 }, k = 1, t = 2;
    bool target = true, ans = containsNearbyAlmostDuplicate(nums, LEN(nums), k, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 1, 5, 9, 1, 5, 9 }, k = 2, t = 3;
    bool target = false, ans = containsNearbyAlmostDuplicate(nums, LEN(nums), k, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int nums[] = {}, k = 0, t = 0;
    bool target = false, ans = containsNearbyAlmostDuplicate(nums, LEN(nums), k, t);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_rb_tree);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}