/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/18 上午11:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>
#include <tree.h>

#include "0109.c"

START_TEST(test_official) {
    int arr1[] = { -10, -3, 0, 5, 9 };
    int arr2[] = { 0, -3, 9, -10, null, 5 };

    list_t l      = list_create(arr1, sizeof(arr1) / sizeof(arr1[0]));
    tree_t target = tree_create(arr2, sizeof(arr2) / sizeof(arr2[0]));

    tree_t ans = sortedListToBST(l);

    fail_if(!tree_equal(target, ans));

    list_free(l);
    tree_free(ans);
    tree_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}