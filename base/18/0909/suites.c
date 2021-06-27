/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/27 下午3:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0909.c"

START_TEST(test_official) {
    int *board[] = { (int[]) { -1, -1, -1, -1, -1, -1 }, (int[]) { -1, -1, -1, -1, -1, -1 },
                     (int[]) { -1, -1, -1, -1, -1, -1 }, (int[]) { -1, 35, -1, -1, 13, -1 },
                     (int[]) { -1, -1, -1, -1, -1, -1 }, (int[]) { -1, 15, -1, -1, -1, -1 } };
    int target = 4, ans = snakesAndLadders(board, LEN(board), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}