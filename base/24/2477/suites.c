/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/12/31 12:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2477.c"

START_TEST(test_official_1) {
    int *roads[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 0, 3 } }, seats = 5;
    int target = 3, ans = minimumFuelCost(roads, LEN(roads), NULL, seats);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *roads[] = { (int[]) { 3, 1 }, (int[]) { 3, 2 }, (int[]) { 1, 0 },
                     (int[]) { 0, 4 }, (int[]) { 0, 5 }, (int[]) { 4, 6 } },
        seats    = 2;
    int target = 7, ans = minimumFuelCost(roads, LEN(roads), NULL, seats);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *roads[] = {}, seats = 1;
    int target = 0, ans = minimumFuelCost(roads, LEN(roads), NULL, seats);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int *roads[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 1, 3 }, (int[]) { 1, 4 } }, seats = 5;
    int target = 4, ans = minimumFuelCost(roads, LEN(roads), NULL, seats);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}