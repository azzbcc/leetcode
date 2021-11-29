/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/29 上午10:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0786.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 5 }, k = 3;
    int target[] = { 2, 5 };
    int len, *ans = kthSmallestPrimeFraction(arr, LEN(arr), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 7 }, k = 1;
    int target[] = { 1, 7 };
    int len, *ans = kthSmallestPrimeFraction(arr, LEN(arr), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}