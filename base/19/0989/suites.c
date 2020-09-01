/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/1 下午6:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0989.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 0, 0 }, K = 34;
    int target[] = { 1, 2, 3, 4 };
    int len, *ans = addToArrayForm(arr, sizeof(arr) / sizeof(arr[0]), K, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int arr[] = { 2, 7, 4 }, K = 181;
    int target[] = { 4, 5, 5 };
    int len, *ans = addToArrayForm(arr, sizeof(arr) / sizeof(arr[0]), K, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_3) {
    int arr[] = { 2, 1, 5 }, K = 806;
    int target[] = { 1, 0, 2, 1 };
    int len, *ans = addToArrayForm(arr, sizeof(arr) / sizeof(arr[0]), K, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_4) {
    int arr[] = { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 }, K = 1;
    int target[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int len, *ans = addToArrayForm(arr, sizeof(arr) / sizeof(arr[0]), K, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_zero) {
    int arr[] = { 0 }, K = 0;
    int target[] = { 0 };
    int len, *ans = addToArrayForm(arr, sizeof(arr) / sizeof(arr[0]), K, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_zero);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}