/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/25 下午6:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>

#include "0410.c"

START_TEST(test_bs) {
    long arr1[] = { 0, 7, 9, 14, 24, 32 };
    long arr2[] = { 32, 25, 23, 18, 8 };

    ck_assert(18 == bs(arr1, arr2, 0, 4));
}

START_TEST(test_official) {
    int arr[] = { 7, 2, 5, 10, 8 }, m = 2, target = 18;
    int ans = splitArray(arr, sizeof(arr) / sizeof(arr[0]), m);

    ck_assert_msg(ans == target, "error, except %d but got %d on splitArray([7, 2, 5, 10, 8], 2).", target, ans);
}

START_TEST(test_failed_1) {
    int arr[] = { 1, 2147483646 }, m = 1, target = 2147483647;
    int ans = splitArray(arr, sizeof(arr) / sizeof(arr[0]), m);

    ck_assert_msg(ans == target, "error, except %d but got %d on splitArray([1, 2147483646], 1).", target, ans);
}

START_TEST(test_failed_2) {
    int arr[] = { 1, 2147483647 }, m = 2, target = 2147483647;
    int ans = splitArray(arr, sizeof(arr) / sizeof(arr[0]), m);

    ck_assert_msg(ans == target, "error, except %d but got %d on splitArray([1, 2147483646], 2).", target, ans);
}

START_TEST(test_failed_3) {
    int arr[] = { 2, 3, 1, 2, 4, 3 }, m = 5, target = 4;
    int ans = splitArray(arr, sizeof(arr) / sizeof(arr[0]), m);

    ck_assert_msg(ans == target, "error, except %d but got %d on splitArray([2, 3, 1, 2, 4, 3], 5).", target, ans);
}

START_TEST(test_failed_4) {
    int arr[] = { 10, 2, 3 }, m = 2, target = 10;
    int ans = splitArray(arr, sizeof(arr) / sizeof(arr[0]), m);

    ck_assert_msg(ans == target, "error, except %d but got %d on splitArray([10, 2, 3], 2).", target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_bs);
    tcase_add_test(t, test_official);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_4);
}