/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/10 下午4:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0025.c"

START_TEST(test_official_1) {
    int arr[]        = { 1, 2, 3, 4, 5 };
    int arr_target[] = { 2, 1, 4, 3, 5 };

    list_t l      = list_create(arr, sizeof(arr) / sizeof(arr[0]));
    list_t target = list_create(arr_target, sizeof(arr_target) / sizeof(arr_target[0]));
    list_t ans    = reverseKGroup(l, 2);

    fail_if(!list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

START_TEST(test_official_2) {
    int arr[]        = { 1, 2, 3, 4, 5 };
    int arr_target[] = { 3, 2, 1, 4, 5 };

    list_t l      = list_create(arr, sizeof(arr) / sizeof(arr[0]));
    list_t target = list_create(arr_target, sizeof(arr_target) / sizeof(arr_target[0]));
    list_t ans    = reverseKGroup(l, 3);

    fail_if(!list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

START_TEST(test_failed) {
    int arr[]        = { 1, 2 };
    int arr_target[] = { 2, 1 };

    list_t l      = list_create(arr, sizeof(arr) / sizeof(arr[0]));
    list_t target = list_create(arr_target, sizeof(arr_target) / sizeof(arr_target[0]));
    list_t ans    = reverseKGroup(l, 2);

    fail_if(!list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}