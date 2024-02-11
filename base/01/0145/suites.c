/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/29 上午10:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0145.c"

START_TEST(test_official_1) {
    int len, arr[] = { 1, null, 2, 3 }, target[] = { 3, 2, 1 };
    tree_t t = tree_create(arr);
    int *ans = postorderTraversal(t, &len);
    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(ans, target, sizeof(target));
    tree_free(t);
    free(ans);
}

START_TEST(test_official_2) {
    int len, arr[] = {}, target[] = {};
    tree_t t = tree_create(arr);
    int *ans = postorderTraversal(t, &len);
    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(ans, target, sizeof(target));
    tree_free(t);
    free(ans);
}

START_TEST(test_official_3) {
    int len, arr[] = { 1 }, target[] = { 1 };
    tree_t t = tree_create(arr);
    int *ans = postorderTraversal(t, &len);
    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(ans, target, sizeof(target));
    tree_free(t);
    free(ans);
}

START_TEST(test_own) {
    int len, arr[] = { 1, 2, 3, 4, 5, 6, 7 }, target[] = { 4, 5, 2, 6, 7, 3, 1 };
    tree_t t = tree_create(arr);
    int *ans = postorderTraversal(t, &len);
    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(ans, target, sizeof(target));
    tree_free(t);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}