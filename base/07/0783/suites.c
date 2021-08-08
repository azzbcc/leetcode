/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/13 下午1:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0783.c"

START_TEST(test_official_1) {
    int arr[] = { 4, 2, 6, 1, 3 };
    tree_t ta = tree_create(arr);

    int target = 1, ans = minDiffInBST(ta);
    ck_assert_int_eq(ans, target);

    tree_free(ta);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 0, 48, null, null, 12, 49 };
    tree_t ta = tree_create(arr);

    int target = 1, ans = minDiffInBST(ta);
    ck_assert_int_eq(ans, target);

    tree_free(ta);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}