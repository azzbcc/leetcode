/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/12 下午1:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1310.c"

START_TEST(test_official_1) {
    int arr[]      = { 1, 3, 4, 8 };
    int *queries[] = { (int[]) { 0, 1 }, (int[]) { 1, 2 }, (int[]) { 0, 3 }, (int[]) { 3, 3 } };
    int target[]   = { 2, 7, 14, 8 };
    int len, *ans = xorQueries(arr, LEN(arr), queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int arr[]      = { 4, 8, 2, 10 };
    int *queries[] = { (int[]) { 2, 3 }, (int[]) { 1, 3 }, (int[]) { 0, 0 }, (int[]) { 0, 3 } };
    int target[]   = { 8, 0, 4, 4 };
    int len, *ans = xorQueries(arr, LEN(arr), queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}