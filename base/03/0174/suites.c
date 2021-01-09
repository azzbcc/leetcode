/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/9 下午10:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0174.c"

START_TEST(test_official) {
    int len = 3, arr[][3] = { { -2, -3, 3 }, { -5, -10, 1 }, { 10, 30, -5 } };
    int *grid[] = { arr[0], arr[1], arr[2] };

    int target = 7, ans = calculateMinimumHP(grid, LEN(grid), &len);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}