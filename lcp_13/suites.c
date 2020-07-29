/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/29 上午11:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>

#include "lcp_13.c"

START_TEST(test_official) {
    char *maze[] = { "S#O", "M..", "M.T" };
    int target = 16, ans = minimalSteps(maze, 3);
    ck_assert_msg(ans == target, "error, except %d but got %d on minimalSteps([\"S#O\", \"M..\", \"M.T\"], 3).", target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}