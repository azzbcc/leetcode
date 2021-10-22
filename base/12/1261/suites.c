/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/22 下午3:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "1261.c"

static void tree_valid_check(tree_t t) {
    if (!t) return;

#define MAXN 0x1000
    int front = 0, rear = 1;
    tree_t queue[MAXN] = { t };

    ck_assert_int_eq(t->val, 0);
    while (front < rear) {
        tree_t now = queue[front];
        front      = (front + 1) % MAXN;
        if (now->left) {
            queue[rear] = now->left, rear = (rear + 1) % MAXN;
            ck_assert_int_eq(now->val * 2 + 1, now->left->val);
        }
        if (now->left) {
            queue[rear] = now->right, rear = (rear + 1) % MAXN;
            ck_assert_int_eq(now->val * 2 + 2, now->right->val);
        }
    }
}

START_TEST(test_official_1) {
    int arr[] = { -1, null, -1 };
    tree_t t  = tree_create(arr);

    FindElements *find = findElementsCreate(t);
    ck_assert_ptr_nonnull(find);
    tree_valid_check(t);

    ck_assert_int_eq(false, findElementsFind(find, 1));
    ck_assert_int_eq(true, findElementsFind(find, 2));

    findElementsFree(find);
    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { -1, -1, -1, -1, -1 };
    tree_t t  = tree_create(arr);

    FindElements *find = findElementsCreate(t);
    ck_assert_ptr_nonnull(find);
    tree_valid_check(t);

    ck_assert_int_eq(true, findElementsFind(find, 1));
    ck_assert_int_eq(true, findElementsFind(find, 3));
    ck_assert_int_eq(false, findElementsFind(find, 5));

    findElementsFree(find);
    tree_free(t);
}

START_TEST(test_official_3) {
    int arr[] = { -1, null, -1, -1, null, -1 };
    tree_t t  = tree_create(arr);

    FindElements *find = findElementsCreate(t);
    ck_assert_ptr_nonnull(find);
    tree_valid_check(t);

    ck_assert_int_eq(true, findElementsFind(find, 2));
    ck_assert_int_eq(false, findElementsFind(find, 3));
    ck_assert_int_eq(false, findElementsFind(find, 4));
    ck_assert_int_eq(true, findElementsFind(find, 5));

    findElementsFree(find);
    tree_free(t);
}

START_TEST(test_own) {
    int arr[0xff];
    for (int i = 0; i < LEN(arr); ++i) {
        arr[i] = i;
    }
    tree_t tree = tree_create(arr);
    tree_valid_check(tree);
    tree_free(tree);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}