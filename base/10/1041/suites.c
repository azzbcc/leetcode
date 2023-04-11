/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/11 下午5:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1041.c"

START_TEST(test_official_1) {
    char *instructions = "GGLLGG";
    ck_assert_int_eq(true, isRobotBounded(instructions));
}

START_TEST(test_official_2) {
    char *instructions = "GG";
    ck_assert_int_eq(false, isRobotBounded(instructions));
}

START_TEST(test_official_3) {
    char *instructions = "GL";
    ck_assert_int_eq(true, isRobotBounded(instructions));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}