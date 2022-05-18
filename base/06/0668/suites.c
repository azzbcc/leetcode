/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/18 上午11:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0668.c"

START_TEST(test_official_1) {
    int m = 3, n = 3, k = 5;
    int target = 3, ans = findKthNumber(m, n, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int m = 2, n = 3, k = 6;
    int target = 6, ans = findKthNumber(m, n, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}