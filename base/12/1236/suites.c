/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/22 上午10:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1236.c"

START_TEST(test_official_1) {
    int startTime[] = { 1, 2, 3, 3 }, endTime[] = { 3, 4, 5, 6 }, profit[] = { 50, 10, 40, 70 };
    int target = 120, ans = jobScheduling(startTime, LEN(startTime), endTime, LEN(endTime), profit, LEN(profit));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int startTime[] = { 1, 2, 3, 4, 6 }, endTime[] = { 3, 5, 10, 6, 9 }, profit[] = { 20, 20, 100, 70, 60 };
    int target = 150, ans = jobScheduling(startTime, LEN(startTime), endTime, LEN(endTime), profit, LEN(profit));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int startTime[] = { 1, 1, 1 }, endTime[] = { 2, 3, 4 }, profit[] = { 5, 6, 4 };
    int target = 6, ans = jobScheduling(startTime, LEN(startTime), endTime, LEN(endTime), profit, LEN(profit));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}