/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/24 上午11:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1705.c"

START_TEST(test_official_1) {
    int apples[] = { 1, 2, 3, 5, 2 }, days[] = { 3, 2, 1, 4, 2 };
    int target = 7, ans = eatenApples(apples, LEN(apples), days, LEN(days));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int apples[] = { 3, 0, 0, 0, 0, 2 }, days[] = { 3, 0, 0, 0, 0, 2 };
    int target = 5, ans = eatenApples(apples, LEN(apples), days, LEN(days));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int apples[] = { 5, 0, 0, 0, 0, 2 }, days[] = { 3, 0, 0, 0, 0, 2 };
    int target = 5, ans = eatenApples(apples, LEN(apples), days, LEN(days));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int apples[] = { 2, 1, 10 }, days[] = { 2, 10, 1 };
    int target = 4, ans = eatenApples(apples, LEN(apples), days, LEN(days));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}