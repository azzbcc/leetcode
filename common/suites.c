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
#include <list.h>
#include <tree.h>

START_TEST(test_list) {
    int arr[] = { 1, 2, 3, 4, 5 };

    list_t l1 = list_create((int[]) { 1, 2, 3, 4, 5 }, 5);
    list_t l2 = list_create(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert(list_equal(l1, l2));

    list_free(l1);
    list_free(l2);
}

START_TEST(test_tree) {
    int arr[] = { 3, 9, 20, null, null, 15, 7 };

    tree_t t1 = tree_create((int[]) { 3, 9, 20, null, null, 15, 7 }, 0, 7);
    tree_t t2 = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    ck_assert(tree_equal(t1, t2));

    tree_free(t1);
    tree_free(t2);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_list);
    tcase_add_test(t, test_tree);
}