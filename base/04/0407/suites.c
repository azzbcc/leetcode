/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/3 下午12:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0407.c"

START_TEST(test_official_1) {
    int col = 6, *map[] = { (int[]) { 1, 4, 3, 1, 3, 2 }, (int[]) { 3, 2, 1, 3, 2, 4 }, (int[]) { 2, 3, 3, 2, 3, 1 } };
    int target = 4, ans = trapRainWater(map, LEN(map), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col = 5, *map[] = { (int[]) { 3, 3, 3, 3, 3 }, (int[]) { 3, 2, 2, 2, 3 }, (int[]) { 3, 2, 1, 2, 3 },
                            (int[]) { 3, 2, 2, 2, 3 }, (int[]) { 3, 3, 3, 3, 3 } };
    int target = 10, ans = trapRainWater(map, LEN(map), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int col = 5, *map[] = { (int[]) { 1, 1, 1, 1, 1 }, (int[]) { 1, 2, 2, 2, 1 }, (int[]) { 1, 2, 1, 2, 1 },
                            (int[]) { 1, 2, 2, 2, 1 }, (int[]) { 1, 1, 1, 1, 1 } };
    int target = 1, ans = trapRainWater(map, LEN(map), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}