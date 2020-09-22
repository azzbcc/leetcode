/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/22 上午13:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0968.c"

START_TEST(test_official_1) {
    int arr[]  = { 0, 0, null, 0, 0 };
    tree_t t   = tree_create(arr, sizeof(arr) / sizeof(arr[0]));
    int target = 1, ans = minCameraCover(t);

    ck_assert_int_eq(target, ans);
    tree_free(t);
}
START_TEST(test_official_2) {
    int arr[]  = { 0, 0, null, 0, null, 0, null, null, 0 };
    tree_t t   = tree_create(arr, sizeof(arr) / sizeof(arr[0]));
    int target = 2, ans = minCameraCover(t);

    ck_assert_int_eq(target, ans);
    tree_free(t);
}
START_TEST(test_failed_1) {
    int arr[]  = { 0 };
    tree_t t   = tree_create(arr, sizeof(arr) / sizeof(arr[0]));
    int target = 1, ans = minCameraCover(t);

    ck_assert_int_eq(target, ans);
    tree_free(t);
}
START_TEST(test_failed_2) {
    int arr[]  = { 0, 0, null, null, 0, 0, null, null, 0, 0 };
    tree_t t   = tree_create(arr, sizeof(arr) / sizeof(arr[0]));
    int target = 2, ans = minCameraCover(t);

    ck_assert_int_eq(target, ans);
    tree_free(t);
}
START_TEST(test_failed_3) {
    int arr[]  = { 0, null, 0, null, 0, null, 0 };
    tree_t t   = tree_create(arr, sizeof(arr) / sizeof(arr[0]));
    int target = 2, ans = minCameraCover(t);

    ck_assert_int_eq(target, ans);
    tree_free(t);
}
START_TEST(test_failed_4) {
    int arr[]  = { 0, null, 0, 0, null, 0, 0, null, null, 0 };
    tree_t t   = tree_create(arr, sizeof(arr) / sizeof(arr[0]));
    int target = 3, ans = minCameraCover(t);

    ck_assert_int_eq(target, ans);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_4);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}