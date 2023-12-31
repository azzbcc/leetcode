/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/12/31 11:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2600.c"

START_TEST(test_official_1) {
    int player1[] = { 4, 10, 7, 9 }, player2[] = { 6, 5, 2, 3 };
    int target = 1, ans = isWinner(player1, LEN(player1), player2, LEN(player2));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int player1[] = { 3, 5, 7, 6 }, player2[] = { 8, 10, 10, 2 };
    int target = 2, ans = isWinner(player1, LEN(player1), player2, LEN(player2));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int player1[] = { 2, 3 }, player2[] = { 4, 1 };
    int target = 0, ans = isWinner(player1, LEN(player1), player2, LEN(player2));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}