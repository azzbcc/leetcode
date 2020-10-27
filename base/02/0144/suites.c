/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/27 上午11:30
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0144.c"

START_TEST(test_official) {
    int arr[] = { 1, null, 2, 3 }, target[] = { 1, 2, 3 };

    tree_t t = tree_create(arr);

    int len, *ans = preorderTraversal(t, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    tree_free(t);
}

START_TEST(test_own) {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }, target[] = { 1, 2, 4, 5, 3, 6, 7 };

    tree_t t = tree_create(arr);

    int len, *ans = preorderTraversal(t, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}