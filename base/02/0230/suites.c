/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/17 上午12:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0230.c"

START_TEST(test_official_1) {
    int k = 1, arr[] = { 3, 1, 4, null, 2 };
    tree_t t = tree_create(arr);

    int target = 1, ans = kthSmallest(t, k);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_official_2) {
    int k = 3, arr[] = { 5, 3, 6, 2, 4, null, null, 1 };
    tree_t t = tree_create(arr);

    int target = 3, ans = kthSmallest(t, k);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}