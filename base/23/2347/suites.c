/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/20 下午2:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2347.c"

START_TEST(test_official_1) {
    int ranks[]  = { 13, 2, 3, 1, 9 };
    char suits[] = "aaaaa";
    char *target = "Flush", *ans = bestHand(ranks, LEN(ranks), suits, LEN(suits));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int ranks[]  = { 4, 4, 2, 4, 4 };
    char suits[] = "daabc";
    char *target = "Three of a Kind", *ans = bestHand(ranks, LEN(ranks), suits, LEN(suits));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int ranks[]  = { 10, 10, 2, 12, 9 };
    char suits[] = "abcad";
    char *target = "Pair", *ans = bestHand(ranks, LEN(ranks), suits, LEN(suits));
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}