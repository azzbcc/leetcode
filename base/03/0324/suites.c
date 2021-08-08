/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/18 下午3:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0324.c"

static void check_array(int arr[], int len) {
    for (int i = 1; i < len; i += 2) {
        ck_assert_int_gt(arr[i], arr[i - 1]);
    }
    for (int i = 2; i < len; i += 2) {
        ck_assert_int_lt(arr[i], arr[i - 1]);
    }
}

START_TEST(test_official_1) {
    int arr[] = { 1, 5, 1, 1, 6, 4 };
    wiggleSort(arr, LEN(arr));
    check_array(arr, LEN(arr));
}

START_TEST(test_official_2) {
    int arr[] = { 1, 3, 2, 2, 3, 1 };
    wiggleSort(arr, LEN(arr));
    check_array(arr, LEN(arr));
}

START_TEST(test_own) {
    int arr[] = { 1, 2, 3, 4, 5 };
    wiggleSort(arr, LEN(arr));
    check_array(arr, LEN(arr));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}