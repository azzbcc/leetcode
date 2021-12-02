/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/2 上午10:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0506.c"

START_TEST(test_official_1) {
    int len, score[] = { 5, 4, 3, 2, 1 };
    char *target[] = { "Gold Medal", "Silver Medal", "Bronze Medal", "4", "5" };
    char **ans     = findRelativeRanks(score, LEN(score), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len, score[] = { 10, 3, 8, 9, 4 };
    char *target[] = { "Gold Medal", "5", "Bronze Medal", "Silver Medal", "4" };
    char **ans     = findRelativeRanks(score, LEN(score), &len);

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