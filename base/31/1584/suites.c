/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/19 下午12:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1584.c"

START_TEST(test_official_1) {
    int *arr[] = { (int[]) { 0, 0 }, (int[]) { 2, 2 }, (int[]) { 3, 10 }, (int[]) { 5, 2 }, (int[]) { 7, 0 } };
    int target = 20, ans = minCostConnectPoints(arr, LEN(arr), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *arr[] = { (int[]) { 3, 12 }, (int[]) { -2, 5 }, (int[]) { -4, 1 } };
    int target = 18, ans = minCostConnectPoints(arr, LEN(arr), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *arr[] = { (int[]) { 0, 0 }, (int[]) { 1, 1 }, (int[]) { 1, 0 }, (int[]) { -1, 1 } };
    int target = 4, ans = minCostConnectPoints(arr, LEN(arr), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int *arr[] = { (int[]) { -1000000, -1000000 }, (int[]) { 1000000, 1000000 } };
    int target = 4000000, ans = minCostConnectPoints(arr, LEN(arr), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int *arr[] = { (int[]) { 0, 0 } };
    int target = 0, ans = minCostConnectPoints(arr, LEN(arr), NULL);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}