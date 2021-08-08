/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/10 下午4:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0872.c"

START_TEST(test_official_1) {
    int arr1[] = { 3, 5, 1, 6, 2, 9, 8, null, null, 7, 4 };
    int arr2[] = { 3, 5, 1, 6, 7, 4, 2, null, null, null, null, null, null, 9, 8 };
    tree_t t1 = tree_create(arr1), t2 = tree_create(arr2);
    ck_assert_int_eq(true, leafSimilar(t1, t2));
    tree_free(t1), tree_free(t2);
}

START_TEST(test_official_2) {
    int arr1[] = { 1 }, arr2[] = { 1 };
    tree_t t1 = tree_create(arr1), t2 = tree_create(arr2);
    ck_assert_int_eq(true, leafSimilar(t1, t2));
    tree_free(t1), tree_free(t2);
}

START_TEST(test_official_3) {
    int arr1[] = { 1 }, arr2[] = { 2 };
    tree_t t1 = tree_create(arr1), t2 = tree_create(arr2);
    ck_assert_int_eq(false, leafSimilar(t1, t2));
    tree_free(t1), tree_free(t2);
}

START_TEST(test_official_4) {
    int arr1[] = { 1, 2 }, arr2[] = { 2, 2 };
    tree_t t1 = tree_create(arr1), t2 = tree_create(arr2);
    ck_assert_int_eq(true, leafSimilar(t1, t2));
    tree_free(t1), tree_free(t2);
}

START_TEST(test_official_5) {
    int arr1[] = { 1, 2, 3 }, arr2[] = { 1, 3, 2 };
    tree_t t1 = tree_create(arr1), t2 = tree_create(arr2);
    ck_assert_int_eq(false, leafSimilar(t1, t2));
    tree_free(t1), tree_free(t2);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}