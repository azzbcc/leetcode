/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/23 下午3:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0753.c"

START_TEST(test_official_1) {
    int n = 1, k = 2;

    char *target = "01", *ans = crackSafe(n, k);

    ck_assert_str_eq(target, ans);

    free(ans);
}

START_TEST(test_official_2) {
    int n = 2, k = 2;

    char *target = "01100", *ans = crackSafe(n, k);

    ck_assert_str_eq(target, ans);

    free(ans);
}

START_TEST(test_own) {
    int n = 2, k = 10;

    char *target = "09988978779686766958575655948474645449383736353433928272625242322918171615141312119080706050403020100", *ans = crackSafe(n, k);

    ck_assert_str_eq(target, ans);

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}