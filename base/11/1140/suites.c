/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/22 下午2:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1140.c"

START_TEST(test_official_1) {
    int piles[] = { 2, 7, 9, 4, 4 };
    int target = 10, ans = stoneGameII(piles, LEN(piles));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int piles[] = { 1, 2, 3, 4, 5, 100 };
    int target = 104, ans = stoneGameII(piles, LEN(piles));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int piles[] = { 1 };
    int target = 1, ans = stoneGameII(piles, LEN(piles));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}