/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/6/21 16:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "lcp_61.c"

START_TEST(test_official_1) {
    int temperatureA[] = { 21, 18, 18, 18, 31 }, temperatureB[] = { 34, 32, 16, 16, 17 };
    int target = 2, ans = temperatureTrend(temperatureA, LEN(temperatureA), temperatureB, LEN(temperatureB));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int temperatureA[] = { 5, 10, 16, -6, 15, 11, 3 }, temperatureB[] = { 16, 22, 23, 23, 25, 3, -16 };
    int target = 3, ans = temperatureTrend(temperatureA, LEN(temperatureA), temperatureB, LEN(temperatureB));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}