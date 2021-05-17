/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/17 上午10:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0993.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 4 }, x = 4, y = 3;
    tree_t t = tree_create(arr);
    ck_assert_int_eq(false, isCousins(t, x, y));
    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2, 3, null, 4, null, 5 }, x = 5, y = 4;
    tree_t t = tree_create(arr);
    ck_assert_int_eq(true, isCousins(t, x, y));
    tree_free(t);
}

START_TEST(test_official_3) {
    int arr[] = { 1, 2, 3, null, 4 }, x = 2, y = 3;
    tree_t t = tree_create(arr);
    ck_assert_int_eq(false, isCousins(t, x, y));
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}