/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/6 上午9:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2180.c"

START_TEST(test_official_1) {
    int num    = 4;
    int target = 2, ans = countEven(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int num    = 30;
    int target = 14, ans = countEven(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int num    = 70;
    int target = 34, ans = countEven(num);
    ck_assert_int_eq(ans, target);
}

static bool is(int x) {
    int ans = 0;
    for (; x; ans += x % 10, x /= 10) {}
    return ans % 2 == 0;
}

START_TEST(test_own) {
    for (int x = 1, c = 0; x <= 1000; ++x) {
        c += is(x);
        ck_assert_int_eq(c, countEven(x));
    }
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}