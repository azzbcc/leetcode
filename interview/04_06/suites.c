/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/16 下午2:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "04_06.c"

START_TEST(test_official_1) {
    int arr[] = { 2, 1, 3 }, p = 1, target = 2;
    tree_t root = tree_create(arr);

    tree_t ans = inorderSuccessor(root, tree_find(root, p));
    ck_assert_ptr_eq(ans, tree_find(root, target));

    tree_free(root);
}
START_TEST(test_official_2) {
    int arr[] = { 5, 3, 6, 2, 4, null, null, 1 }, p = 6, target = null;
    tree_t root = tree_create(arr);

    tree_t ans = inorderSuccessor(root, tree_find(root, p));
    ck_assert_ptr_eq(ans, tree_find(root, target));

    tree_free(root);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}