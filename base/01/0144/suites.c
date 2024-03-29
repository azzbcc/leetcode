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

START_TEST(test_official_1) {
    int arr[] = { 1, null, 2, 3 }, target[] = { 1, 2, 3 };
    tree_t t = tree_create(arr);
    int len, *ans = preorderTraversal(t, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    tree_free(t);
    free(ans);
}

START_TEST(test_official_2) {
    int arr[] = {}, target[] = {};
    tree_t t = tree_create(arr);
    int len, *ans = preorderTraversal(t, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    tree_free(t);
    free(ans);
}

START_TEST(test_official_3) {
    int arr[] = { 1 }, target[] = { 1 };
    tree_t t = tree_create(arr);
    int len, *ans = preorderTraversal(t, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    tree_free(t);
    free(ans);
}

START_TEST(test_official_4) {
    int arr[] = { 1, 2 }, target[] = { 1, 2 };
    tree_t t = tree_create(arr);
    int len, *ans = preorderTraversal(t, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    tree_free(t);
    free(ans);
}

START_TEST(test_official_5) {
    int arr[] = { 1, null, 2 }, target[] = { 1, 2 };
    tree_t t = tree_create(arr);
    int len, *ans = preorderTraversal(t, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    tree_free(t);
    free(ans);
}

START_TEST(test_own) {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }, target[] = { 1, 2, 4, 5, 3, 6, 7 };
    tree_t t = tree_create(arr);
    int len, *ans = preorderTraversal(t, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    tree_free(t);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}