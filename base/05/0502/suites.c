/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/8 上午10:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0502.c"

START_TEST(test_official_1) {
    int k = 2, w = 0, profits[] = { 1, 2, 3 }, capital[] = { 0, 1, 1 };
    int target = 4, ans = findMaximizedCapital(k, w, profits, LEN(profits), capital, LEN(capital));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int k = 3, w = 0, profits[] = { 1, 2, 3 }, capital[] = { 0, 1, 2 };
    int target = 6, ans = findMaximizedCapital(k, w, profits, LEN(profits), capital, LEN(capital));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}