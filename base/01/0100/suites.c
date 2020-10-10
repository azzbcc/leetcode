/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/7 上午00:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0100.c"

START_TEST(test_official_1) {
    int arr1[] = { 1, 2, 3 }, arr2[] = { 1, 2, 3 };

    tree_t t1 = tree_create(arr1);
    tree_t t2 = tree_create(arr2);

    bool target = true, ans = isSameTree(t1, t2);

    fail_if(target != ans);

    tree_free(t1);
    tree_free(t2);
}

START_TEST(test_official_2) {
    int arr1[] = { 1, 2 }, arr2[] = { 1, null, 2 };

    tree_t t1 = tree_create(arr1);
    tree_t t2 = tree_create(arr2);

    bool target = false, ans = isSameTree(t1, t2);

    fail_if(target != ans);

    tree_free(t1);
    tree_free(t2);
}

START_TEST(test_official_3) {
    int arr1[] = { 1, 2, 1 }, arr2[] = { 1, 1, 2 };

    tree_t t1 = tree_create(arr1);
    tree_t t2 = tree_create(arr2);

    bool target = false, ans = isSameTree(t1, t2);

    fail_if(target != ans);

    tree_free(t1);
    tree_free(t2);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}