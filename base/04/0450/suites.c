/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/2 上午10:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0450.c"

void tree_check(tree_t t, int key) {
    if (!t) return;
    ck_assert_int_ne(t->val, key);
    tree_check(t->left, key);
    tree_check(t->right, key);
}

START_TEST(test_official_1) {
    int arr[] = { 5, 3, 6, 2, 4, null, 7 }, key = 3;
    tree_t t = tree_create(arr);

    tree_t ans = deleteNode(t, key);
    tree_check(ans, key);
    tree_free(ans);
}

START_TEST(test_official_2) {
    int arr[] = { 5, 3, 6, 2, 4, null, 7 }, key = 0;
    tree_t t = tree_create(arr);

    tree_t ans = deleteNode(t, key);
    tree_check(ans, key);
    tree_free(ans);
}

START_TEST(test_official_3) {
    int arr[] = {}, key = 0;
    tree_t t = tree_create(arr);

    tree_t ans = deleteNode(t, key);
    tree_check(ans, key);
    tree_free(ans);
}

START_TEST(test_own) {
    int arr[] = { 9, 1, null, null, 5, 3, 7, 2, 4, 6, 8 }, key = 5;
    tree_t t = tree_create(arr);

    tree_t ans = deleteNode(t, key);
    tree_check(ans, key);
    tree_free(ans);
}

START_TEST(test_failed) {
    int arr[] = { 2, 1 }, key = 2;
    tree_t t = tree_create(arr);

    tree_t ans = deleteNode(t, key);
    tree_check(ans, key);
    tree_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}