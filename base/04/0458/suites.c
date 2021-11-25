/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/25 上午10:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0458.c"

START_TEST(test_official_1) {
    int buckets = 1000, minutesToDie = 15, minutesToTest = 60;
    int target = 5, ans = poorPigs(buckets, minutesToDie, minutesToTest);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int buckets = 4, minutesToDie = 15, minutesToTest = 15;
    int target = 2, ans = poorPigs(buckets, minutesToDie, minutesToTest);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int buckets = 4, minutesToDie = 15, minutesToTest = 30;
    int target = 2, ans = poorPigs(buckets, minutesToDie, minutesToTest);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}