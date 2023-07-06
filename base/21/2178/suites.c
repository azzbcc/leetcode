/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/6 14:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2178.c"

START_TEST(test_official_1) {
    int len;
    long long finalSum = 12;
    long long target[] = { 2, 4, 6 };
    long long *ans     = maximumEvenSplit(finalSum, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    long long finalSum = 7;
    long long target[] = {};
    long long *ans     = maximumEvenSplit(finalSum, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int len;
    long long finalSum = 28;
    long long target[] = { 2, 4, 6, 16 };
    long long *ans     = maximumEvenSplit(finalSum, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_limit) {
    int len;
    long long finalSum      = 10000000000;
    long long target[99999] = { [99998] = 299998 };
    long long *ans          = maximumEvenSplit(finalSum, &len);
    for (int i = 1; i < LEN(target); target[i - 1] = i * 2, ++i) {}
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}