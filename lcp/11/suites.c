/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/23 下午6:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "lcp_11.c"

START_TEST(test_official_1) {
    int scores[] = { 1, 2, 3 };
    int target = 3, ans = expectNumber(scores, LEN(scores));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int scores[] = { 1, 1 };
    int target = 1, ans = expectNumber(scores, LEN(scores));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int scores[] = { 1, 1, 2 };
    int target = 2, ans = expectNumber(scores, LEN(scores));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}