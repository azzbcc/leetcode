/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/2 15:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0822.c"

START_TEST(test_official_1) {
    int fronts[] = { 1, 2, 4, 4, 7 }, backs[] = { 1, 3, 4, 1, 3 };
    int target = 2, ans = flipgame(fronts, LEN(fronts), backs, LEN(backs));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int fronts[] = { 1 }, backs[] = { 1 };
    int target = 0, ans = flipgame(fronts, LEN(fronts), backs, LEN(backs));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}