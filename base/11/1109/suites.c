/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/31 上午10:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1109.c"

START_TEST(test_official_1) {
    int n           = 5;
    int *bookings[] = { (int[]) { 1, 2, 10 }, (int[]) { 2, 3, 20 }, (int[]) { 2, 5, 25 } };

    int target[] = { 10, 55, 45, 25, 25 };
    int len, *ans = corpFlightBookings(bookings, LEN(bookings), NULL, n, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int n           = 2;
    int *bookings[] = { (int[]) { 1, 2, 10 }, (int[]) { 2, 2, 15 } };

    int target[] = { 10, 25 };
    int len, *ans = corpFlightBookings(bookings, LEN(bookings), NULL, n, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}