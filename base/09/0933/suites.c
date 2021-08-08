/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/6 下午3:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0933.c"

START_TEST(test_official) {
    RecentCounter *counter = recentCounterCreate();

    ck_assert_int_eq(1, recentCounterPing(counter, 1));
    ck_assert_int_eq(2, recentCounterPing(counter, 100));
    ck_assert_int_eq(3, recentCounterPing(counter, 3001));
    ck_assert_int_eq(3, recentCounterPing(counter, 3002));

    recentCounterFree(counter);
}

START_TEST(test_own) {
    RecentCounter *counter = recentCounterCreate();
    for (int i = 0; i <= 3000; ++i) {
        ck_assert_int_eq(i + 1, recentCounterPing(counter, i));
    }
    for (int i = 3001; i <= 10000; ++i) {
        ck_assert_int_eq(3001, recentCounterPing(counter, i));
    }
    recentCounterFree(counter);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}