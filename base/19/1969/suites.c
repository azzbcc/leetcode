/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/20 20:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1969.c"

START_TEST(test_official_1) {
    int p = 1, target = 1, ans = minNonZeroProduct(p);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int p = 2, target = 6, ans = minNonZeroProduct(p);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int p = 3, target = 1512, ans = minNonZeroProduct(p);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    ck_assert_int_eq(minNonZeroProduct(4), 581202553);
    ck_assert_int_eq(minNonZeroProduct(60), 813987236);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}