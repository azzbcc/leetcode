/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 20-7-23 下午18:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0001.c"

START_TEST(test_official_1) {
    int arr[] = { 2, 7, 11, 15 }, t = 9, target[] = { 0, 1 };
    int len, *ans = twoSum(arr, LEN(arr), t, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 2, 4 }, t = 6, target[] = { 1, 2 };
    int len, *ans = twoSum(arr, LEN(arr), t, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int arr[] = { 3, 3 }, t = 6, target[] = { 0, 1 };
    int len, *ans = twoSum(arr, LEN(arr), t, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}