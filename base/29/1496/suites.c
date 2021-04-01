/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/1 下午4:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1496.c"

START_TEST(test_official_1) {
    char *path  = "NES";
    bool target = false, ans = isPathCrossing(path);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *path  = "NESWW";
    bool target = true, ans = isPathCrossing(path);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}