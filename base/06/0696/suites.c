/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/10 上午0:22
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0696.c"

START_TEST(test_official_1) {
    char *input = "00110011";
    int target = 6, ans = countBinarySubstrings(input);

    ck_assert_msg(target == ans, "error, except %d but got %d on countBinarySubstrings('%s').", target, ans, input);
}

START_TEST(test_official_2) {
    char *input = "10101";
    int target = 4, ans = countBinarySubstrings(input);

    ck_assert_msg(target == ans, "error, except %d but got %d on countBinarySubstrings('%s').", target, ans, input);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}