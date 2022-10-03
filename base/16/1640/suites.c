/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/9/22 上午11:30
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1640.c"

START_TEST(test_official_1) {
    int arr[]     = { 15, 88 };
    int col[]     = { 1, 1 };
    int *pieces[] = { (int[]) { 88 }, (int[]) { 15 } };
    bool target = true, ans = canFormArray(arr, LEN(arr), pieces, LEN(pieces), col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]     = { 49, 18, 16 };
    int col[]     = { 3 };
    int *pieces[] = { (int[]) { 16, 18, 49 } };
    bool target = false, ans = canFormArray(arr, LEN(arr), pieces, LEN(pieces), col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]     = { 91, 4, 64, 78 };
    int col[]     = { 1, 2, 1 };
    int *pieces[] = { (int[]) { 78 }, (int[]) { 4, 64 }, (int[]) { 91 } };
    bool target = true, ans = canFormArray(arr, LEN(arr), pieces, LEN(pieces), col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}