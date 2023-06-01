/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/1 11:57
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2517.c"

START_TEST(test_official_1) {
    int price[] = { 13, 5, 1, 8, 21, 2 }, k = 3;
    int target = 8, ans = maximumTastiness(price, LEN(price), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int price[] = { 1, 3, 1 }, k = 2;
    int target = 2, ans = maximumTastiness(price, LEN(price), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int price[] = { 7, 7, 7, 7 }, k = 2;
    int target = 0, ans = maximumTastiness(price, LEN(price), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}