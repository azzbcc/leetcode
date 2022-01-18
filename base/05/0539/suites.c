/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/18 下午12:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0539.c"

START_TEST(test_official_1) {
    char *timePoints[] = { "23:59", "00:00" };
    int target = 1, ans = findMinDifference(timePoints, LEN(timePoints));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *timePoints[] = { "00:00", "23:59", "00:00" };
    int target = 0, ans = findMinDifference(timePoints, LEN(timePoints));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}