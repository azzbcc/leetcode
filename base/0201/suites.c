/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/23 上午1:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0201.c"

START_TEST(test_official_1) {
    int target = 4, ans = rangeBitwiseAnd(5, 7);
    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int target = 0, ans = rangeBitwiseAnd(0, 1);
    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase* t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}
