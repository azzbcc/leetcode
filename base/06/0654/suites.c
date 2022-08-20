/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/20 下午3:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0654.c"

START_TEST(test_official_1) {
    int arr[]    = { 3, 2, 1, 6, 0, 5 };
    int target[] = { 6, 3, 5, null, 2, 0, null, null, 1 };

    tree_t t = tree_create(target), ans = constructMaximumBinaryTree(arr, LEN(arr));
    ck_assert(tree_equal(ans, t));

    tree_free(ans);
    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[]    = { 3, 2, 1 };
    int target[] = { 3, null, 2, null, 1 };

    tree_t t = tree_create(target), ans = constructMaximumBinaryTree(arr, LEN(arr));
    ck_assert(tree_equal(ans, t));

    tree_free(ans);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}