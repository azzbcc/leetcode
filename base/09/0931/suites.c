/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/13 15:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0931.c"

START_TEST(test_official_1) {
    int *matrix[] = { (int[]) { 2, 1, 3 }, (int[]) { 6, 5, 4 }, (int[]) { 7, 8, 9 } };
    int target = 13, ans = minFallingPathSum(matrix, LEN(matrix), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *matrix[] = { (int[]) { -19, 57 }, (int[]) { -40, -5 } };
    int target = -59, ans = minFallingPathSum(matrix, LEN(matrix), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}