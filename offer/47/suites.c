/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/8 上午10:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "offer_47.c"

START_TEST(test_official) {
    int col = 3, *grid[] = { (int[]) { 1, 3, 1 }, (int[]) { 1, 5, 1 }, (int[]) { 4, 2, 1 } };
    int target = 12, ans = maxValue(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}