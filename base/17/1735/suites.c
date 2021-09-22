/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/25 下午2:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1735.c"

START_TEST(test_official_1) {
    int *arr[]   = { (int[]) { 2, 6 }, (int[]) { 5, 1 }, (int[]) { 73, 660 } };
    int target[] = { 4, 1, 50734910 };
    int len, *ans = waysToFillArray(arr, LEN(arr), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int *arr[]   = { (int[]) { 1, 1 }, (int[]) { 2, 2 }, (int[]) { 3, 3 }, (int[]) { 4, 4 }, (int[]) { 5, 5 } };
    int target[] = { 1, 2, 3, 10, 5 };
    int len, *ans = waysToFillArray(arr, LEN(arr), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int *arr[]   = { (int[]) { 8, 7 }, (int[]) { 13, 2 }, (int[]) { 1, 9 }, (int[]) { 10, 9 } };
    int target[] = { 8, 13, 1, 55 };
    int len, *ans = waysToFillArray(arr, LEN(arr), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}