/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 20-7-24 下午12:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1025.c"

START_TEST(test_official) {
    ck_assert_msg(divisorGame(2) == true, "error, except true but got false on minPathSum(2).");
    ck_assert_msg(divisorGame(3) == false, "error, except false but got true on minPathSum(3).");
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}