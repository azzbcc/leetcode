/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/26 上午11:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2013.c"

#define null INT32_MIN

START_TEST(test_official) {
    DetectSquares *squares = detectSquaresCreate();

    char *commands[] = { "add", "add", "add", "count", "count", "add", "count" };
    int args[][2]    = { { 3, 10 }, { 11, 2 }, { 3, 2 }, { 11, 10 }, { 14, 8 }, { 11, 2 }, { 11, 10 } };
    int target[]     = { null, null, null, 1, 0, null, 2 };

    for (int i = 0; i < LEN(commands); ++i) {
        if (!strcmp(commands[i], "add")) {
            detectSquaresAdd(squares, args[i], LEN(args[i]));
        } else {
            ck_assert_int_eq(target[i], detectSquaresCount(squares, args[i], LEN(args[i])));
        }
    }

    detectSquaresFree(squares);
}

START_TEST(test_failed) {
    DetectSquares *squares = detectSquaresCreate();

    char *commands[] = { "add", "add", "add", "count", "add", "add", "add", "count",
                         "add", "add", "add", "count", "add", "add", "add", "count" };
    int args[][2]    = { { 5, 10 }, { 10, 5 }, { 10, 10 }, { 5, 5 }, { 3, 0 }, { 8, 0 }, { 8, 5 }, { 3, 5 },
                      { 9, 0 },  { 9, 8 },  { 1, 8 },   { 1, 0 }, { 0, 0 }, { 8, 0 }, { 8, 8 }, { 0, 8 } };
    int target[]     = { null, null, null, 1, null, null, null, 1, null, null, null, 1, null, null, null, 2 };

    for (int i = 0; i < LEN(commands); ++i) {
        if (!strcmp(commands[i], "add")) {
            detectSquaresAdd(squares, args[i], LEN(args[i]));
        } else {
            ck_assert_int_eq(target[i], detectSquaresCount(squares, args[i], LEN(args[i])));
        }
    }

    detectSquaresFree(squares);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}