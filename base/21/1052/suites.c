/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/23 上午12:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1052.c"

START_TEST(test_official) {
    int customers[] = { 1, 0, 1, 2, 1, 1, 7, 5 }, grumpy[] = { 0, 1, 0, 1, 0, 1, 0, 1 }, X = 3;
    int target = 16, ans = maxSatisfied(customers, LEN(customers), grumpy, LEN(grumpy), X);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}