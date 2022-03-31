/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/31 上午11:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2100.c"

static int array_comp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}

START_TEST(test_official_1) {
    int security[] = { 5, 3, 3, 3, 5, 6, 2 }, time = 2;
    int target[] = { 2, 3 };
    int len, *ans = goodDaysToRobBank(security, LEN(security), time, &len);
    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int security[] = { 1, 1, 1, 1, 1 }, time = 0;
    int target[] = { 0, 1, 2, 3, 4 };
    int len, *ans = goodDaysToRobBank(security, LEN(security), time, &len);
    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int security[] = { 1, 2, 3, 4, 5, 6 }, time = 2;
    int target[] = {};
    int len, *ans = goodDaysToRobBank(security, LEN(security), time, &len);
    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}