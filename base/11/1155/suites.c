/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/24 10:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1155.c"

START_TEST(test_official_1) {
    int n = 1, k = 6, t = 3;
    int target = 1, ans = numRollsToTarget(n, k, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 2, k = 6, t = 7;
    int target = 6, ans = numRollsToTarget(n, k, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 30, k = 30, t = 500;
    int target = 222616187, ans = numRollsToTarget(n, k, t);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}