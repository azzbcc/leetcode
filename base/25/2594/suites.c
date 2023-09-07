/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/7 12:28
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2594.c"

START_TEST(test_official_1) {
    int ranks[] = { 4, 2, 3, 1 }, cars = 10;
    long long target = 16, ans = repairCars(ranks, LEN(ranks), cars);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int ranks[] = { 5, 1, 8 }, cars = 6;
    long long target = 16, ans = repairCars(ranks, LEN(ranks), cars);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}