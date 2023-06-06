/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/7 06:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2611.c"

START_TEST(test_official_1) {
    int reward1[] = { 1, 1, 3, 4 }, reward2[] = { 4, 4, 1, 1 }, k = 2;
    int target = 15, ans = miceAndCheese(reward1, LEN(reward1), reward2, LEN(reward2), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int reward1[] = { 1, 1 }, reward2[] = { 1, 1 }, k = 2;
    int target = 2, ans = miceAndCheese(reward1, LEN(reward1), reward2, LEN(reward2), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int reward1[] = { 1, 2, 2 }, reward2[] = { 2, 1, 2 }, k = 2;
    int target = 6, ans = miceAndCheese(reward1, LEN(reward1), reward2, LEN(reward2), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}