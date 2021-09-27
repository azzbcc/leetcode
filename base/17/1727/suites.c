/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/17 下午11:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1727.c"

START_TEST(test_official_1) {
    int col = 3, *arr[] = { (int[]) { 0, 0, 1 }, (int[]) { 1, 1, 1 }, (int[]) { 1, 0, 1 } };
    int target = 4, ans = largestSubmatrix(arr, LEN(arr), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col = 5, *arr[] = { (int[]) { 1, 0, 1, 0, 1 } };
    int target = 3, ans = largestSubmatrix(arr, LEN(arr), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int col = 3, *arr[] = { (int[]) { 1, 1, 0 }, (int[]) { 1, 0, 1 } };
    int target = 2, ans = largestSubmatrix(arr, LEN(arr), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int col = 2, *arr[] = { (int[]) { 0, 0 }, (int[]) { 0, 0 } };
    int target = 0, ans = largestSubmatrix(arr, LEN(arr), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int col = 9, *arr[] = { (int[]) { 0, 1, 1, 1, 0, 1, 1, 1, 0 }, (int[]) { 1, 1, 0, 1, 1, 1, 1, 1, 1 },
                            (int[]) { 1, 1, 1, 1, 0, 1, 1, 0, 1 }, (int[]) { 1, 1, 1, 1, 1, 1, 0, 1, 0 },
                            (int[]) { 1, 1, 1, 1, 1, 1, 1, 1, 0 }, (int[]) { 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                            (int[]) { 1, 1, 1, 0, 1, 1, 0, 1, 1 }, (int[]) { 1, 1, 1, 1, 1, 0, 0, 1, 1 },
                            (int[]) { 1, 1, 0, 1, 1, 1, 1, 1, 1 }, (int[]) { 1, 1, 1, 1, 1, 1, 1, 0, 1 },
                            (int[]) { 1, 1, 1, 1, 1, 1, 1, 1, 1 }, (int[]) { 1, 0, 1, 1, 0, 1, 0, 1, 1 },
                            (int[]) { 1, 1, 1, 1, 1, 1, 1, 1, 1 }, (int[]) { 1, 0, 0, 1, 1, 1, 1, 1, 1 },
                            (int[]) { 1, 1, 1, 1, 0, 1, 1, 0, 1 }, (int[]) { 1, 1, 0, 0, 0, 1, 1, 1, 1 },
                            (int[]) { 0, 1, 0, 0, 1, 1, 1, 1, 1 }, (int[]) { 1, 1, 1, 1, 1, 0, 1, 1, 1 } };
    int target = 28, ans = largestSubmatrix(arr, LEN(arr), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
    int col = 1, base[] = { 1 }, *arr[100000] = {};
    for (int i = 0; i < LEN(arr); arr[i++] = base) {}
    int target = 100000, ans = largestSubmatrix(arr, LEN(arr), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}
