/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/17 上午11:37
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "1302.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 4, 5, null, 6, 7, null, null, null, null, 8 };
    tree_t t  = tree_create(arr);

    int target = 15, ans = deepestLeavesSum(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { 6, 7, 8, 2, 7, 1, 3, 9, null, 1, 4, null, null, null, 5 };
    tree_t t  = tree_create(arr);

    int target = 19, ans = deepestLeavesSum(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}