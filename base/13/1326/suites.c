/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/21 下午2:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1326.c"

START_TEST(test_official_1) {
    int n = 5, ranges[] = { 3, 4, 1, 1, 0, 0 };
    int target = 1, ans = minTaps(n, ranges, LEN(ranges));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 3, ranges[] = { 0, 0, 0, 0 };
    int target = -1, ans = minTaps(n, ranges, LEN(ranges));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int n = 3, ranges[] = { 0, 1, 2, 0 };
    int target = 1, ans = minTaps(n, ranges, LEN(ranges));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int n = 8, ranges[] = { 4, 0, 0, 0, 4, 0, 0, 0, 4 };
    int target = 1, ans = minTaps(n, ranges, LEN(ranges));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int n = 9, ranges[] = { 0, 5, 0, 3, 3, 3, 1, 4, 0, 4 };
    int target = 2, ans = minTaps(n, ranges, LEN(ranges));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}