/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/9 下午8:22
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1475.c"

START_TEST(test_official_1) {
    int arr[]    = { 8, 4, 6, 2, 3 };
    int target[] = { 4, 2, 4, 2, 3 };
    int len, *ans = finalPrices(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int arr[]    = { 1, 2, 3, 4, 5 };
    int target[] = { 1, 2, 3, 4, 5 };
    int len, *ans = finalPrices(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_3) {
    int arr[]    = { 10, 1, 1, 6 };
    int target[] = { 9, 0, 1, 6 };
    int len, *ans = finalPrices(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}