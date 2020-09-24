/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/24 下午2:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0992.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 1, 2, 3 }, K = 2;
    int target = 7, ans = subarraysWithKDistinct(arr, sizeof(arr) / sizeof(arr[0]), K);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2, 1, 3, 4 }, K = 3;
    int target = 3, ans = subarraysWithKDistinct(arr, sizeof(arr) / sizeof(arr[0]), K);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int arr[] = { 2, 1, 1, 1, 2 }, K = 1;
    int target = 8, ans = subarraysWithKDistinct(arr, sizeof(arr) / sizeof(arr[0]), K);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}