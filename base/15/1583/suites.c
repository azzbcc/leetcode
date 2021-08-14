/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/14 上午9:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1583.c"

START_TEST(test_official_1) {
    int n              = 4;
    int *preferences[] = { (int[]) { 1, 2, 3 }, (int[]) { 3, 2, 0 }, (int[]) { 3, 1, 0 }, (int[]) { 1, 2, 0 } };
    int *pairs[]       = { (int[]) { 0, 1 }, (int[]) { 2, 3 } };
    int target = 2, ans = unhappyFriends(n, preferences, LEN(preferences), NULL, pairs, LEN(pairs), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n              = 2;
    int *preferences[] = { (int[]) { 1 }, (int[]) { 0 } };
    int *pairs[]       = { (int[]) { 1, 0 } };
    int target = 0, ans = unhappyFriends(n, preferences, LEN(preferences), NULL, pairs, LEN(pairs), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n              = 4;
    int *preferences[] = { (int[]) { 1, 3, 2 }, (int[]) { 2, 3, 0 }, (int[]) { 1, 3, 0 }, (int[]) { 0, 2, 1 } };
    int *pairs[]       = { (int[]) { 1, 3 }, (int[]) { 0, 2 } };
    int target = 4, ans = unhappyFriends(n, preferences, LEN(preferences), NULL, pairs, LEN(pairs), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}