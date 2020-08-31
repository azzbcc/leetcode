/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/29 下午18:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0738.c"

START_TEST(test_official_1) {
    int N      = 10;
    int target = 9, ans = monotoneIncreasingDigits(N);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_2) {
    int N      = 1234;
    int target = 1234, ans = monotoneIncreasingDigits(N);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_3) {
    int N      = 332;
    int target = 299, ans = monotoneIncreasingDigits(N);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_own) {
    int N      = 15433;
    int target = 14999, ans = monotoneIncreasingDigits(N);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}