/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/19 14:30
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1883.c"

START_TEST(test_official_1) {
    int dist[] = { 1, 3, 2 }, speed = 4, hoursBefore = 2;
    int target = 1, ans = minSkips(dist, LEN(dist), speed, hoursBefore);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int dist[] = { 7, 3, 5, 5 }, speed = 2, hoursBefore = 10;
    int target = 2, ans = minSkips(dist, LEN(dist), speed, hoursBefore);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int dist[] = { 7, 3, 5, 5 }, speed = 1, hoursBefore = 10;
    int target = -1, ans = minSkips(dist, LEN(dist), speed, hoursBefore);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}