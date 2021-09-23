/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/5 上午13:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0014.c"

START_TEST(test_official_1) {
    char *input[] = { "flower", "flow", "flight" };
    char *target = "fl", *ans = longestCommonPrefix(input, LEN(input));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *input[] = { "dog", "racecar", "car" };
    char *target = "", *ans = longestCommonPrefix(input, LEN(input));
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}