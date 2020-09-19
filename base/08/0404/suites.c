/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/19 下午9:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0404.c"

START_TEST(test_official) {
    int arr[]  = { 3, 9, 20, null, null, 15, 7 };
    tree_t t   = tree_create(arr, sizeof(arr) / sizeof(arr[0]));
    int target = 24, ans = sumOfLeftLeaves(t);

    ck_assert_int_eq(target, ans);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}