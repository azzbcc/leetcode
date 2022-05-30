/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/30 上午9:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "1022.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 0, 1, 0, 1, 0, 1 };
    tree_t t  = tree_create(arr);

    int target = 22, ans = sumRootToLeaf(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { 0 };
    tree_t t  = tree_create(arr);

    int target = 0, ans = sumRootToLeaf(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}