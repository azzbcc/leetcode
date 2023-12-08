/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/12/8 15:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2008.c"

START_TEST(test_official_1) {
    int n = 5, *rides[] = { (int[]) { 2, 5, 4 }, (int[]) { 1, 5, 1 } };
    long long target = 7, ans = maxTaxiEarnings(n, rides, LEN(rides), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 20, *rides[] = { (int[]) { 1, 6, 1 },   (int[]) { 3, 10, 2 },  (int[]) { 10, 12, 3 },
                             (int[]) { 11, 12, 2 }, (int[]) { 12, 15, 2 }, (int[]) { 13, 18, 1 } };
    long long target = 20, ans = maxTaxiEarnings(n, rides, LEN(rides), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}