/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/1 下午1:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1006.c"

START_TEST(test_official_1) {
    int target = 7, ans = clumsy(4);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int target = 12, ans = clumsy(10);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}