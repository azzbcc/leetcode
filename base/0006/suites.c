/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/3 下午4:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */

#include <check.h>
#include <stdlib.h>

#include "0006.c"

START_TEST(test_official_1) {
    char input[] = "LEETCODEISHIRING";
    char *target = "LCIRETOESIIGEDHN", *ans = convert(input, 3);

    ck_assert_msg(!strcmp(target, ans), "error, except %s but got %s on convert().", target, ans);
}

START_TEST(test_official_2) {
    char input[] = "LEETCODEISHIRING";
    char *target = "LDREOEIIECIHNTSG", *ans = convert(input, 4);

    ck_assert_msg(!strcmp(target, ans), "error, except %s but got %s on convert().", target, ans);
}

START_TEST(test_failed) {
    char input[] = "A";
    char *target = "A", *ans = convert(input, 2);

    ck_assert_msg(!strcmp(target, ans), "error, except %s but got %s on convert().", target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}