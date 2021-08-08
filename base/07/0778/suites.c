/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/30 下午1:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0778.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 0, 2 }, (int[]) { 1, 3 } };
    int target = 3, ans = swimInWater(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 0, 1, 2, 3, 4 }, (int[]) { 24, 23, 22, 21, 5 }, (int[]) { 12, 13, 14, 15, 16 },
                    (int[]) { 11, 17, 18, 19, 20 }, (int[]) { 10, 9, 8, 7, 6 } };
    int target = 16, ans = swimInWater(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}