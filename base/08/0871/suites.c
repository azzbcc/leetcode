/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/7 17:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0871.c"

START_TEST(test_official_1) {
    int t = 1, startFuel = 1, *stations[] = {};
    int target = 0, ans = minRefuelStops(t, startFuel, stations, LEN(stations), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int t = 100, startFuel = 1, *stations[] = { (int[]) { 10, 100 } };
    int target = -1, ans = minRefuelStops(t, startFuel, stations, LEN(stations), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int t = 100, startFuel = 10;
    int *stations[] = { (int[]) { 10, 60 }, (int[]) { 20, 30 }, (int[]) { 30, 30 }, (int[]) { 60, 40 } };
    int target = 2, ans = minRefuelStops(t, startFuel, stations, LEN(stations), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow) {
    int t = 1000, startFuel = 83;
    int *stations[] = { (int[]) { 15, 457 },  (int[]) { 156, 194 }, (int[]) { 160, 156 }, (int[]) { 230, 314 },
                        (int[]) { 390, 159 }, (int[]) { 621, 20 },  (int[]) { 642, 123 }, (int[]) { 679, 301 },
                        (int[]) { 739, 229 }, (int[]) { 751, 174 } };
    int target = 3, ans = minRefuelStops(t, startFuel, stations, LEN(stations), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_overflow);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}