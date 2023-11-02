/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/11/2 12:37
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2103.c"

START_TEST(test_official_1) {
    char *rings = "B0B6G0R6R0R6G9";
    int target = 1, ans = countPoints(rings);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *rings = "B0R0G0R9R0B0G0";
    int target = 1, ans = countPoints(rings);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *rings = "G4";
    int target = 0, ans = countPoints(rings);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}