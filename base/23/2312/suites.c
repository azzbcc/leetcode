/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/15 09:41
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2312.c"

START_TEST(test_official_1) {
    int m = 3, n = 5, *prices[] = { (int[]) { 1, 4, 2 }, (int[]) { 2, 2, 7 }, (int[]) { 2, 1, 3 } };
    long long target = 19, ans = sellingWood(m, n, prices, LEN(prices), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int m = 4, n = 6, *prices[] = { (int[]) { 3, 2, 10 }, (int[]) { 1, 4, 2 }, (int[]) { 4, 1, 3 } };
    long long target = 32, ans = sellingWood(m, n, prices, LEN(prices), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}