/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/23 下午1:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1319.c"

START_TEST(test_official_1) {
    int n = 4, *arr[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 1, 2 } };
    int target = 1, ans = makeConnected(n, arr, LEN(arr), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 6, *arr[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 0, 3 }, (int[]) { 1, 2 }, (int[]) { 1, 3 } };
    int target = 2, ans = makeConnected(n, arr, LEN(arr), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 6, *arr[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 0, 3 }, (int[]) { 1, 2 } };
    int target = -1, ans = makeConnected(n, arr, LEN(arr), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int n = 5, *arr[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 3, 4 }, (int[]) { 2, 3 } };
    int target = 0, ans = makeConnected(n, arr, LEN(arr), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}