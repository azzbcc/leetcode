/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/24 上午9:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0965.c"

START_TEST(test_official_1) {
    int arr[]   = { 1, 1, 1, 1, 1, null, 1 };
    tree_t t    = tree_create(arr);
    bool target = true, ans = isUnivalTree(t);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[]   = { 2, 2, 2, 5, 2 };
    tree_t t    = tree_create(arr);
    bool target = false, ans = isUnivalTree(t);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}