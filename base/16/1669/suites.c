/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/30 下午2:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "1669.c"

START_TEST(test_official_1) {
    int a = 3, b = 4;
    int arr1[] = { 0, 1, 2, 3, 4, 5 };
    int arr2[] = { 1000000, 1000001, 1000002 };
    int tarr[] = { 0, 1, 2, 1000000, 1000001, 1000002, 5 };

    list_t target = list_create(tarr);
    list_t ans    = mergeInBetween(list_create(arr1), a, b, list_create(arr2));
    ck_assert(list_equal(ans, target));

    list_free(ans);
    list_free(target);
}

START_TEST(test_official_2) {
    int a = 2, b = 5;
    int arr1[] = { 0, 1, 2, 3, 4, 5, 6 };
    int arr2[] = { 1000000, 1000001, 1000002, 1000003, 1000004 };
    int tarr[] = { 0, 1, 1000000, 1000001, 1000002, 1000003, 1000004, 6 };

    list_t target = list_create(tarr);
    list_t ans    = mergeInBetween(list_create(arr1), a, b, list_create(arr2));
    ck_assert(list_equal(ans, target));

    list_free(ans);
    list_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}