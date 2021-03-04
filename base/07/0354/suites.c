/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/4 上午11:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0354.c"

START_TEST(test_official) {
    int *grid[] = { (int[]) { 5, 4 }, (int[]) { 6, 4 }, (int[]) { 6, 7 }, (int[]) { 2, 3 } };
    int target = 3, ans = maxEnvelopes(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int *grid[] = {};
    int target = 0, ans = maxEnvelopes(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}