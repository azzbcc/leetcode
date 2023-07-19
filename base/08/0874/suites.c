/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/19 15:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0874.c"

START_TEST(test_official_1) {
    int commands[] = { 4, -1, 3 }, *obstacles[] = {};
    int target = 25, ans = robotSim(commands, LEN(commands), obstacles, LEN(obstacles), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int commands[] = { 4, -1, 4, -2, 4 }, *obstacles[] = { (int[]) { 2, 4 } };
    int target = 65, ans = robotSim(commands, LEN(commands), obstacles, LEN(obstacles), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int commands[] = { 6, -1, -1, 6 }, *obstacles[] = {};
    int target = 36, ans = robotSim(commands, LEN(commands), obstacles, LEN(obstacles), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}