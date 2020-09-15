/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/17 上午11:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0110.c"

START_TEST(test_official_1) {
    int arr[] = { 3, 9, 20, null, null, 15, 7 };
    tree_t t  = tree_create(arr, sizeof(arr) / sizeof(arr[0]));

    bool target = true, ans = isBalanced(t);

    fail_if(target != ans);

    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2, 2, 3, 3, null, null, 4, 4 };
    tree_t t  = tree_create(arr, sizeof(arr) / sizeof(arr[0]));

    bool target = false, ans = isBalanced(t);

    fail_if(target != ans);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}