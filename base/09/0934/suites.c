/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/25 上午11:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0934.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 0, 1 }, (int[]) { 1, 0 } };
    int target = 1, ans = shortestBridge(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 0, 1, 0 }, (int[]) { 0, 0, 0 }, (int[]) { 0, 0, 1 } };
    int target = 2, ans = shortestBridge(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *grid[] = { (int[]) { 1, 1, 1, 1, 1 }, (int[]) { 1, 0, 0, 0, 1 }, (int[]) { 1, 0, 1, 0, 1 },
                    (int[]) { 1, 0, 0, 0, 1 }, (int[]) { 1, 1, 1, 1, 1 } };
    int target = 1, ans = shortestBridge(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int *grid[] = { (int[]) { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, (int[]) { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    (int[]) { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, (int[]) { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    (int[]) { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, (int[]) { 0, 1, 1, 1, 1, 0, 0, 1, 0, 0 },
                    (int[]) { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 }, (int[]) { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                    (int[]) { 1, 0, 1, 1, 1, 1, 1, 1, 1, 0 }, (int[]) { 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 } };
    int target = 1, ans = shortestBridge(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}