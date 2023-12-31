/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/12/31 11:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2661.c"

START_TEST(test_official_1) {
    int col = 2, arr[] = { 1, 3, 4, 2 }, *mat[] = { (int[]) { 1, 4 }, (int[]) { 2, 3 } };
    int target = 2, ans = firstCompleteIndex(arr, LEN(arr), mat, LEN(mat), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col = 3, arr[] = { 2, 8, 7, 4, 1, 3, 5, 6, 9 },
        *mat[] = { (int[]) { 3, 2, 5 }, (int[]) { 1, 4, 6 }, (int[]) { 8, 7, 9 } };
    int target = 3, ans = firstCompleteIndex(arr, LEN(arr), mat, LEN(mat), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}