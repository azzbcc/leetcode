/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/4 上午10:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1823.c"

START_TEST(test_official_1) {
    int n = 5, k = 2;
    int target = 3, ans = findTheWinner(n, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 6, k = 5;
    int target = 1, ans = findTheWinner(n, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}