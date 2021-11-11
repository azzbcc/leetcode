/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/11 上午10:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0629.c"

START_TEST(test_official_1) {
    int n = 3, k = 0;
    int target = 1, ans = kInversePairs(n, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 3, k = 1;
    int target = 2, ans = kInversePairs(n, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}