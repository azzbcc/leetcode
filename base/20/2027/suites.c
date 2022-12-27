/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/27 下午4:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2027.c"

START_TEST(test_official_1) {
    char *s    = "XXX";
    int target = 1, ans = minimumMoves(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = "XXOX";
    int target = 2, ans = minimumMoves(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s    = "OOOO";
    int target = 0, ans = minimumMoves(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}