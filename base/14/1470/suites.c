/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/29 上午11:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1470.c"

START_TEST(test_official_1) {
    int arr[]    = { 2, 5, 1, 3, 4, 7 };
    int target[] = { 2, 3, 5, 4, 1, 7 };
    int len, *ans = shuffle(arr, LEN(arr), LEN(arr) / 2, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int arr[]    = { 1, 2, 3, 4, 4, 3, 2, 1 };
    int target[] = { 1, 4, 2, 3, 3, 2, 4, 1 };
    int len, *ans = shuffle(arr, LEN(arr), LEN(arr) / 2, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int arr[]    = { 1, 1, 2, 2 };
    int target[] = { 1, 2, 1, 2 };
    int len, *ans = shuffle(arr, LEN(arr), LEN(arr) / 2, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}