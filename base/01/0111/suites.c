/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/21 上午11:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0111.c"

START_TEST(test_official) {
    int arr[] = { 3, 9, 20, null, null, 15, 7 };
    tree_t t  = tree_create(arr);

    int target = 2, ans = minDepth(t);

    ck_assert_int_eq(target, ans);

    tree_free(t);
}

START_TEST(test_failed) {
    int arr[] = { 1, 2 };
    tree_t t  = tree_create(arr);

    int target = 2, ans = minDepth(t);

    ck_assert_int_eq(target, ans);

    tree_free(t);
}

START_TEST(test_limit) {
    int arr[] = {
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null, 0, null,
        0, null, 0, null, 0, 0
    };
    tree_t t = tree_create(arr);

    int target = 1804, ans = minDepth(t);

    ck_assert_int_eq(target, ans);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}
