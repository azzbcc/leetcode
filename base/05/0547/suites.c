/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/7 上午11:28
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0547.c"

START_TEST(test_official_1) {
    int arr[][3] = { { 1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } };
    int *grid[]  = { arr[0], arr[1], arr[2] };

    int target = 2, ans = findCircleNum(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[][3] = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
    int *grid[]  = { arr[0], arr[1], arr[2] };

    int target = 3, ans = findCircleNum(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}