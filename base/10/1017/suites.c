/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/6 下午2:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1017.c"

START_TEST(test_official_1) {
    int n        = 2;
    char *target = "110", *ans = baseNeg2(n);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int n        = 3;
    char *target = "111", *ans = baseNeg2(n);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int n        = 4;
    char *target = "100", *ans = baseNeg2(n);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_own) {
    ck_assert_str_eq("1001100111011111101111000000000", baseNeg2(1000000000));
}

void tcase_complete(TCase *t) {
    printf("%d\n", -3 / -2);
    printf("%d\n", -3 % 2);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}