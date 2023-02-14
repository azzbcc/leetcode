/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/14 下午2:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1124.c"

START_TEST(test_official_1) {
    int hours[] = { 9, 9, 6, 0, 6, 6, 9 };
    int target = 3, ans = longestWPI(hours, LEN(hours));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int hours[] = { 6, 6, 6 };
    int target = 0, ans = longestWPI(hours, LEN(hours));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int hours[] = { 9, 9, 6, 0, 6, 9, 6 };
    int target = 3, ans = longestWPI(hours, LEN(hours));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int hours[] = { 12, 8, 7, 7, 9, 10, 8, 7, 9, 7, 8, 11 };
    int target = 5, ans = longestWPI(hours, LEN(hours));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}