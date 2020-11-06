/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/6 上午11:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1356.c"

START_TEST(test_official_1) {
    int arr[]    = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    int target[] = { 0, 1, 2, 4, 8, 3, 5, 6, 7 };

    int len, *ans = sortByBits(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int arr[]    = { 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1 };
    int target[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };

    int len, *ans = sortByBits(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_3) {
    int arr[]    = { 10000, 10000 };
    int target[] = { 10000, 10000 };

    int len, *ans = sortByBits(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_4) {
    int arr[]    = { 2, 3, 5, 7, 11, 13, 17, 19 };
    int target[] = { 2, 3, 5, 17, 7, 11, 13, 19 };

    int len, *ans = sortByBits(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_5) {
    int arr[]    = { 10, 100, 1000, 10000 };
    int target[] = { 10, 100, 10000, 1000 };

    int len, *ans = sortByBits(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}