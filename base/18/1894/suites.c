/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/10 上午10:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1894.c"

START_TEST(test_official_1) {
    int chalk[] = { 5, 1, 5 }, k = 22;
    int target = 0, ans = chalkReplacer(chalk, LEN(chalk), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int chalk[] = { 3, 4, 1, 2 }, k = 25;
    int target = 1, ans = chalkReplacer(chalk, LEN(chalk), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}