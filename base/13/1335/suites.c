/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/16 12:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1335.c"

START_TEST(test_official_1) {
    int jobDifficulty[] = { 6, 5, 4, 3, 2, 1 }, d = 2;
    int target = 7, ans = minDifficulty(jobDifficulty, LEN(jobDifficulty), d);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int jobDifficulty[] = { 9, 9, 9 }, d = 4;
    int target = -1, ans = minDifficulty(jobDifficulty, LEN(jobDifficulty), d);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int jobDifficulty[] = { 1, 1, 1 }, d = 3;
    int target = 3, ans = minDifficulty(jobDifficulty, LEN(jobDifficulty), d);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int jobDifficulty[] = { 7, 1, 7, 1, 7, 1 }, d = 3;
    int target = 15, ans = minDifficulty(jobDifficulty, LEN(jobDifficulty), d);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int jobDifficulty[] = { 11, 111, 22, 222, 33, 333, 44, 444 }, d = 6;
    int target = 843, ans = minDifficulty(jobDifficulty, LEN(jobDifficulty), d);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}