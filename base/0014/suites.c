/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/5 上午13:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>
#include <stdbool.h>

#include "0014.c"

START_TEST(test_official_1) {
    char *input[] = { "flower", "flow", "flight" };
    char *target = "fl", *ans = longestCommonPrefix(input, sizeof(input) / sizeof(input[0]));
    ck_assert_msg(!strcmp(target, ans), "error, except %d but got %d on longestCommonPrefix().", target, ans);
}

START_TEST(test_official_2) {
    char *input[] = { "dog", "racecar", "car" };
    char *target = "", *ans = longestCommonPrefix(input, sizeof(input) / sizeof(input[0]));
    ck_assert_msg(!strcmp(target, ans), "error, except %d but got %d on longestCommonPrefix().", target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}