/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/20 14:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0105.c"

START_TEST(test_official_1) {
    int preorder[] = { 3, 9, 20, 15, 7 }, inorder[] = { 9, 3, 15, 20, 7 };
    int target[] = { 3, 9, 20, null, null, 15, 7 };
    tree_t t = tree_create(target), ans = buildTree(preorder, LEN(preorder), inorder, LEN(inorder));
    ck_assert(tree_equal(ans, t));
    tree_free(ans);
    tree_free(t);
}

START_TEST(test_official_2) {
    int preorder[] = { -1 }, inorder[] = { -1 }, target[] = { -1 };
    tree_t t = tree_create(target), ans = buildTree(preorder, LEN(preorder), inorder, LEN(inorder));
    ck_assert(tree_equal(ans, t));
    tree_free(ans);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}