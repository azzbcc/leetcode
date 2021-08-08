/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/24 下午12:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0222.c"

START_TEST(test_official) {
    int arr[] = { 1, 2, 3, 4, 5, 6 };

    tree_t t = tree_create(arr);

    int target = LEN(arr), ans = countNodes(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_own) {
    int arr[120] = { 0 };
    for (int i = 0; i < LEN(arr); ++i) {
        arr[i] = i + 1;
    }

    tree_t t = tree_create(arr);

    int target = LEN(arr), ans = countNodes(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}