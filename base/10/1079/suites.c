/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/19 14:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1079.c"

START_TEST(test_official_1) {
    char *tiles = "AAB";
    int target = 8, ans = numTilePossibilities(tiles);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *tiles = "AAABBC";
    int target = 188, ans = numTilePossibilities(tiles);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *tiles = "V";
    int target = 1, ans = numTilePossibilities(tiles);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}