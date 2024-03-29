/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/10 上午11:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0021.c"

START_TEST(test_official_1) {
    int arr1[] = { 1, 2, 4 }, arr2[] = { 1, 3, 4 }, arr3[] = { 1, 1, 2, 3, 4, 4 };
    list_t l1 = list_create(arr1), l2 = list_create(arr2), target = list_create(arr3);

    list_t ans = mergeTwoLists(l1, l2);

    ck_assert(list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

START_TEST(test_official_2) {
    int arr1[] = {}, arr2[] = {}, arr3[] = {};
    list_t l1 = list_create(arr1), l2 = list_create(arr2), target = list_create(arr3);

    list_t ans = mergeTwoLists(l1, l2);

    ck_assert(list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

START_TEST(test_official_3) {
    int arr1[] = {}, arr2[] = { 0 }, arr3[] = { 0 };
    list_t l1 = list_create(arr1), l2 = list_create(arr2), target = list_create(arr3);

    list_t ans = mergeTwoLists(l1, l2);

    ck_assert(list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}