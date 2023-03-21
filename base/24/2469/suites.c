/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/21 下午2:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2469.c"

START_TEST(test_official_1) {
    int len;
    double celsius  = 36.50;
    double target[] = { 309.65000, 97.70000 };
    double *ans     = convertTemperature(celsius, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.00001);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    double celsius  = 122.11;
    double target[] = { 395.26000, 251.79800 };
    double *ans     = convertTemperature(celsius, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.00001);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}