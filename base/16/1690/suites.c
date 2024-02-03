/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/3 10:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1690.c"

START_TEST(test_official_1) {
    int stones[] = { 5, 3, 1, 4, 2 };
    int target = 6, ans = stoneGameVII(stones, LEN(stones));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int stones[] = { 7, 90, 5, 1, 100, 10, 10, 2 };
    int target = 122, ans = stoneGameVII(stones, LEN(stones));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}