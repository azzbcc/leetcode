/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/27 14:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2580.c"

START_TEST(test_official_1) {
    int *ranges[] = { (int[]) { 6, 10 }, (int[]) { 5, 15 } };
    int target = 2, ans = countWays(ranges, LEN(ranges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *ranges[] = { (int[]) { 1, 3 }, (int[]) { 10, 20 }, (int[]) { 2, 5 }, (int[]) { 4, 8 } };
    int target = 4, ans = countWays(ranges, LEN(ranges), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}