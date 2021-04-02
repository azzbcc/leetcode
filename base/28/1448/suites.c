/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/2 下午3:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "1448.c"

START_TEST(test_official_1) {
    int arr[] = { 3, 1, 4, 3, null, 1, 5 };
    tree_t t  = tree_create(arr);

    int target = 4, ans = goodNodes(t);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 3, null, 4, 2 };
    tree_t t  = tree_create(arr);

    int target = 3, ans = goodNodes(t);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

START_TEST(test_official_3) {
    int arr[] = { 1 };
    tree_t t  = tree_create(arr);

    int target = 1, ans = goodNodes(t);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

START_TEST(test_failed) {
    int arr[] = { -1, 5,    -2, 4,    4,  2,  -2, null, null, -4,   null, -2,   3,    null, -2, 0, null,
                  -1, null, -3, null, -4, -3, 3,  null, null, null, null, null, null, null, 3,  -3 };
    tree_t t  = tree_create(arr);

    int target = 5, ans = goodNodes(t);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}