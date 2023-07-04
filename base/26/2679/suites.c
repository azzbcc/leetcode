/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/4 11:57
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2679.c"

START_TEST(test_official_1) {
    int *nums[] = { (int[]) { 7, 2, 1 }, (int[]) { 6, 4, 2 }, (int[]) { 6, 5, 3 }, (int[]) { 3, 2, 1 } };
    int col = 3, target = 15, ans = matrixSum(nums, LEN(nums), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *nums[] = { (int[]) { 1 } };
    int col = 1, target = 1, ans = matrixSum(nums, LEN(nums), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}