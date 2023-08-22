/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/22 15:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0849.c"

START_TEST(test_official_1) {
    int seats[] = { 1, 0, 0, 0, 1, 0, 1 };
    int target = 2, ans = maxDistToClosest(seats, LEN(seats));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int seats[] = { 1, 0, 0, 0 };
    int target = 3, ans = maxDistToClosest(seats, LEN(seats));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int seats[] = { 0, 1 };
    int target = 1, ans = maxDistToClosest(seats, LEN(seats));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}