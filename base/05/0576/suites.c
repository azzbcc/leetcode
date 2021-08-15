/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/15 上午10:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0576.c"

START_TEST(test_official_1) {
    int m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
    int target = 6, ans = findPaths(m, n, maxMove, startRow, startColumn);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;
    int target = 12, ans = findPaths(m, n, maxMove, startRow, startColumn);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}