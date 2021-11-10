/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/10 上午11:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0495.c"

START_TEST(test_official_1) {
    int timeSeries[] = { 1, 4 }, duration = 2;
    int target = 4, ans = findPoisonedDuration(timeSeries, LEN(timeSeries), duration);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int timeSeries[] = { 1, 2 }, duration = 2;
    int target = 3, ans = findPoisonedDuration(timeSeries, LEN(timeSeries), duration);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}