/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/21 上午11:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0838.c"

START_TEST(test_official_1) {
    char dominoes[] = "RR.L";
    char *target = "RR.L", *ans = pushDominoes(dominoes);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char dominoes[] = ".L.R...LR..L..";
    char *target = "LL.RR.LLRRLL..", *ans = pushDominoes(dominoes);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_own) {
    char dominoes[] = ".L.R...LR..R..";
    char *target = "LL.RR.LLRRRRRR", *ans = pushDominoes(dominoes);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_1) {
    char dominoes[] = ".";
    char *target = ".", *ans = pushDominoes(dominoes);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_2) {
#include "tle.c"
    char *ans = pushDominoes(dominoes);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_3) {
    char dominoes[] = ".R..L.";
    char *target = ".RRLL.", *ans = pushDominoes(dominoes);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}