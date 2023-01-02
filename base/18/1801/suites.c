/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/2 下午4:41
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1801.c"

START_TEST(test_official_1) {
    int *orders[] = { (int[]) { 10, 5, 0 }, (int[]) { 15, 2, 1 }, (int[]) { 25, 1, 1 }, (int[]) { 30, 4, 0 } };
    int target = 6, ans = getNumberOfBacklogOrders(orders, LEN(orders), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *orders[] = { (int[]) { 7, 1000000000, 1 }, (int[]) { 15, 3, 0 }, (int[]) { 5, 999999995, 0 },
                      (int[]) { 5, 1, 1 } };
    int target = 999999984, ans = getNumberOfBacklogOrders(orders, LEN(orders), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
#include "failed.c"
    int target = 225818155, ans = getNumberOfBacklogOrders(orders, LEN(orders), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}