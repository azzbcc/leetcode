/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/9 上午9:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2379.c"

START_TEST(test_official_1) {
    char *blocks = "WBBWWBBWBW";
    int k = 7, target = 3, ans = minimumRecolors(blocks, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *blocks = "WBWBBBW";
    int k = 2, target = 0, ans = minimumRecolors(blocks, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow) {
    char *blocks = "BWWWBB";
    int k = 6, target = 3, ans = minimumRecolors(blocks, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *blocks = "WBWW";
    int k = 2, target = 1, ans = minimumRecolors(blocks, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_overflow);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}