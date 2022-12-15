/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/15 上午9:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1945.c"

START_TEST(test_official_1) {
    char *s    = "iiii";
    int k      = 1;
    int target = 36, ans = getLucky(s, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = "leetcode";
    int k      = 2;
    int target = 6, ans = getLucky(s, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}