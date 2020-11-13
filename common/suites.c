/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/20 下午4:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <23_tree.h>
#include <avl_tree.h>
#include <list.h>
#include <rb_tree.h>
#include <tree.h>

static int max(int a, int b) {
    return a > b ? a : b;
}

static void _23_tree_check(_23_tree_t t) {
    if (!t) return;
    ck_assert(t->count >= 2 && t->count <= 3);
    if (t->count == 3) ck_assert_int_lt(t->val[0], t->val[1]);

    int c = 0;
    for (int i = 0; i < t->count; ++i) {
        c += t->children[i] != NULL;
    }
    ck_assert(c == 0 || c == t->count);
    if (!c) return;

    _23_tree_t *child = t->children;
    ck_assert_int_ge(t->val[0], child[0]->val[child[0]->count - 2]);
    ck_assert_int_le(t->val[t->count - 2], child[t->count - 1]->val[0]);
    if (t->count == 3) {
        ck_assert_int_le(t->val[0], child[1]->val[0]);
        ck_assert_int_ge(t->val[1], child[1]->val[child[1]->count - 2]);
    }

    for (int i = 0; i < t->count; ++i) {
        ck_assert_ptr_eq(t->children[i]->parent, t);
        _23_tree_check(t->children[i]);
    }
}

START_TEST(test_23_tree) {
    int arr[]    = { 30 };
    _23_tree_t t = _23_tree_create(arr);

    for (int i = 1; i <= 10; ++i) {
        _23_tree_add(&t, 30 + i);
        _23_tree_check(t);
    }
    for (int i = 1; i <= 10; ++i) {
        _23_tree_add(&t, 30 - i);
        _23_tree_check(t);
    }
    for (int i = 0; i < 200; ++i) {
        _23_tree_add(&t, rand() % 100);
        _23_tree_check(t);
    }

    for (int i = 0; i < 500; ++i) {
        _23_tree_del(&t, rand() % 100);
        _23_tree_check(t);
    }

    _23_tree_free(t);
}

static void avl_tree_check(avl_tree_t t) {
    if (!t) return;
    int left = avl_tree_height(t->left), right = avl_tree_height(t->right), balance = left - right;
    ck_assert_int_le(abs(balance), 1);
    ck_assert_int_eq(avl_tree_height(t), max(left, right) + 1);
    avl_tree_check(t->left);
    avl_tree_check(t->right);
}

START_TEST(test_avl_tree) {
    int arr[]    = { 30 };
    avl_tree_t t = avl_tree_create(arr);

    for (int i = 1; i <= 10; ++i) {
        avl_tree_add(&t, 30 + i);
        avl_tree_check(t);
    }
    for (int i = 1; i <= 10; ++i) {
        avl_tree_add(&t, 30 - i);
        avl_tree_check(t);
    }
    for (int i = 0; i < 50; ++i) {
        avl_tree_add(&t, rand() % 100);
        avl_tree_check(t);
    }

    for (int i = 0; i < 100; ++i) {
        avl_tree_del(&t, rand() % 100);
        avl_tree_check(t);
    }

    avl_tree_free(t);
}

START_TEST(test_list) {
    int arr[] = { 1, 2, 3, 4, 5 };

    list_t l1 = list_create(((int[]) { 1, 2, 3, 4, 5 }));
    list_t l2 = list_create(arr);

    ck_assert(list_equal(l1, l2));
    ck_assert_ptr_eq(list_index(l1, 2), list_find(l1, 3));

    list_free(l1);
    list_free(l2);
}

static void rb_tree_check(rb_tree_t t) {
    if (!t) return;

    const int MAXN = 0x1000;
    int front = 0, rear = 0, black_count = -1;
    struct node {
        rb_tree_t tree;
        int count;
    } queue[MAXN];

    ck_assert_int_eq(BLACK, rb_tree_color(t));
    ck_assert_ptr_eq(t->parent, NULL);
    queue[rear++] = (struct node) { t, 1 };
    while (front < rear) {
        struct node now = queue[front];
        front           = (front + 1) % MAXN;

        if (RED == rb_tree_color(now.tree)) {
            ck_assert_int_eq(BLACK, rb_tree_color(now.tree->left));
            ck_assert_int_eq(BLACK, rb_tree_color(now.tree->right));
        }
        if (!now.tree) {
            if (black_count < 0) black_count = now.count;
            ck_assert_int_eq(black_count, now.count);
        } else {
            queue[rear] = (struct node) { now.tree->left, now.count + !rb_tree_color(now.tree->left) };
            rear        = (rear + 1) % MAXN;
            queue[rear] = (struct node) { now.tree->right, now.count + !rb_tree_color(now.tree->right) };
            rear        = (rear + 1) % MAXN;
        }
    }
}

START_TEST(test_rb_tree) {
    int arr[]   = { 30 };
    rb_tree_t t = rb_tree_create(arr);
    rb_tree_check(t);

    for (int i = 1; i <= 10; ++i) {
        rb_tree_add(&t, 30 + i);
        rb_tree_check(t);
    }
    for (int i = 1; i <= 10; ++i) {
        rb_tree_add(&t, 30 - i);
        rb_tree_check(t);
    }
    for (int i = 0; i < 200; ++i) {
        rb_tree_add(&t, rand() % 100);
        rb_tree_check(t);
    }

    for (int i = 0; i < 500; ++i) {
        rb_tree_del(&t, rand() % 100);
        rb_tree_check(t);
    }

    rb_tree_free(t);
}

START_TEST(test_tree) {
    int arr[] = { 3, 9, 20, null, null, 15, 7 };

    tree_t t1 = tree_create(((int[]) { 3, 9, 20, null, null, 15, 7 }));
    tree_t t2 = tree_create(arr);

    ck_assert(tree_equal(t1, t2));

    tree_free(t1);
    tree_free(t2);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_23_tree);
    tcase_add_test(t, test_avl_tree);
    tcase_add_test(t, test_list);
    tcase_add_test(t, test_rb_tree);
    tcase_add_test(t, test_tree);
}