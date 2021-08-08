/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/9 下午8:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1482.c"

START_TEST(test_official_1) {
    int bloomDay[] = { 1, 10, 3, 10, 2 }, m = 3, k = 1;
    int target = 3, ans = minDays(bloomDay, LEN(bloomDay), m, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int bloomDay[] = { 1, 10, 3, 10, 2 }, m = 3, k = 2;
    int target = -1, ans = minDays(bloomDay, LEN(bloomDay), m, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int bloomDay[] = { 7, 7, 7, 7, 12, 7, 7 }, m = 2, k = 3;
    int target = 12, ans = minDays(bloomDay, LEN(bloomDay), m, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int bloomDay[] = { 1000000000, 1000000000 }, m = 1, k = 1;
    int target = 1000000000, ans = minDays(bloomDay, LEN(bloomDay), m, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int bloomDay[] = { 1, 10, 2, 9, 3, 8, 4, 7, 5, 6 }, m = 4, k = 2;
    int target = 9, ans = minDays(bloomDay, LEN(bloomDay), m, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}