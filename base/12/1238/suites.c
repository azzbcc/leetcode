/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/23 下午7:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1238.c"

START_TEST(test_official_1) {
    int n = 2, start = 3;
    int len, *ans    = circularPermutation(n, start, &len);
    ck_assert_int_eq(len, 1 << n);
    for (int i = 1; i < len; ++i) {
        ck_assert_int_eq(1, __builtin_popcount(ans[i] ^ ans[i - 1]));
    }
    free(ans);
}

START_TEST(test_official_2) {
    int n = 3, start = 2;
    int len, *ans    = circularPermutation(n, start, &len);
    ck_assert_int_eq(len, 1 << n);
    for (int i = 1; i < len; ++i) {
        ck_assert_int_eq(1, __builtin_popcount(ans[i] ^ ans[i - 1]));
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}