/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/11 上午11:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "0130.c"

START_TEST(test_official) {
    int len       = 4;
    char *parr[4] = { NULL }, arr[][5] = { "XXXX", "XOOX", "XXOX", "XOXX" };
    char target[][5] = { "XXXX", "XXXX", "XXXX", "XOXX" };
    for (int i = 0; i < sizeof(parr) / sizeof(parr[0]); ++i) {
        parr[i] = arr[i];
    }

    solve(parr, sizeof(parr) / sizeof(parr[0]), &len);

    for (int i = 0; i < sizeof(parr) / sizeof(parr[0]); ++i) {
        ck_assert_str_eq(arr[i], target[i]);
    }
}

START_TEST(test_failed) {
    int len       = 1;
    char *parr[1] = { NULL }, arr[][2] = { "O" };
    char target[][2] = { "O" };
    for (int i = 0; i < sizeof(parr) / sizeof(parr[0]); ++i) {
        parr[i] = arr[i];
    }

    solve(parr, sizeof(parr) / sizeof(parr[0]), &len);

    for (int i = 0; i < sizeof(parr) / sizeof(parr[0]); ++i) {
        ck_assert_str_eq(arr[i], target[i]);
    }
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}