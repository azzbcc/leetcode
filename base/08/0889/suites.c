/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/22 11:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0889.c"

START_TEST(test_official_1) {
    int preorder[] = { 1, 2, 4, 5, 3, 6, 7 }, postorder[] = { 4, 5, 2, 6, 7, 3, 1 };
    int target[] = { 1, 2, 3, 4, 5, 6, 7 };
    tree_t t = tree_create(target), ans = constructFromPrePost(preorder, LEN(preorder), postorder, LEN(postorder));
    ck_assert(tree_equal(ans, t));
    tree_free(ans);
    tree_free(t);
}

START_TEST(test_official_2) {
    int preorder[] = { 1 }, postorder[] = { 1 };
    int target[] = { 1 };
    tree_t t = tree_create(target), ans = constructFromPrePost(preorder, LEN(preorder), postorder, LEN(postorder));
    ck_assert(tree_equal(ans, t));
    tree_free(ans);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}