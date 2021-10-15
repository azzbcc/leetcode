/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/15 下午2:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "078.c"

START_TEST(test_official_1) {
    int col[]        = { 3, 3, 2 };
    int *arr[]       = { (int[]) { 1, 4, 5 }, (int[]) { 1, 3, 4 }, (int[]) { 2, 6 } };
    int arr_target[] = { 1, 1, 2, 3, 4, 4, 5, 6 };

    list_t lists[LEN(arr)] = { NULL };
    for (int i = 0; i < LEN(arr); ++i) {
        lists[i] = list_create_size(arr[i], col[i]);
    }
    list_t target = list_create(arr_target);
    list_t ans    = mergeKLists(lists, LEN(arr));

    ck_assert(list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

START_TEST(test_official_2) {
    int col[]        = {};
    int *arr[]       = {};
    int arr_target[] = {};

    list_t lists[LEN(arr)] = { NULL };
    for (int i = 0; i < LEN(arr); ++i) {
        lists[i] = list_create_size(arr[i], col[i]);
    }
    list_t target = list_create(arr_target);
    list_t ans    = mergeKLists(lists, LEN(arr));

    ck_assert(list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

START_TEST(test_official_3) {
    int col[]        = { 0 };
    int *arr[]       = { (int[]) {} };
    int arr_target[] = {};

    list_t lists[LEN(arr)] = { NULL };
    for (int i = 0; i < LEN(arr); ++i) {
        lists[i] = list_create_size(arr[i], col[i]);
    }
    list_t target = list_create(arr_target);
    list_t ans    = mergeKLists(lists, LEN(arr));

    ck_assert(list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}