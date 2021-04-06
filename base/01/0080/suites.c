/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/6 下午1:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0080.c"

START_TEST(test_official_1) {
    int arr[]    = { 1, 1, 1, 2, 2, 3 };
    int target[] = { 1, 1, 2, 2, 3 };

    int ans = removeDuplicates(arr, LEN(arr));
    ck_assert_int_eq(ans, LEN(target));
    ck_assert_mem_eq(arr, target, sizeof(target));
}

START_TEST(test_official_2) {
    int arr[]    = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
    int target[] = { 0, 0, 1, 1, 2, 3, 3 };

    int ans = removeDuplicates(arr, LEN(arr));
    ck_assert_int_eq(ans, LEN(target));
    ck_assert_mem_eq(arr, target, sizeof(target));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}