/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/30 上午12:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0784.c"

START_TEST(test_official_1) {
    int len;
    char *s        = "a1b2";
    char *target[] = { "a1b2", "A1b2", "a1B2", "A1B2" };
    char **ans     = letterCasePermutation(s, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *s        = "3z4";
    char *target[] = { "3z4", "3Z4" };
    char **ans     = letterCasePermutation(s, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}