/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/7/10 上午12:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0741.c"

START_TEST(test_official) {
    int *grid[] = { (int[]) { 0, 1, -1 }, (int[]) { 1, 0, -1 }, (int[]) { 1, 1, 1 } };
    int target = 5, ans = cherryPickup(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int *grid[] = { (int[]) { 1, 1, 1, 0, 0 }, (int[]) { 0, 0, 1, 0, 1 }, (int[]) { 1, 0, 1, 0, 0 },
                    (int[]) { 0, 0, 1, 0, 0 }, (int[]) { 0, 0, 1, 1, 1 } };
    int target = 11, ans = cherryPickup(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int *grid[] = { (int[]) { 1, 1, -1 }, (int[]) { 1, -1, 1 }, (int[]) { -1, 1, 1 } };
    int target = 0, ans = cherryPickup(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}