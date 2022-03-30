/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/30 下午6:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1606.c"

static int array_comp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}

START_TEST(test_official_1) {
    int k = 3, arrival[] = { 1, 2, 3, 4, 5 }, load[] = { 5, 2, 3, 3, 3 };
    int len, target[] = { 1 };
    int *ans = busiestServers(k, arrival, LEN(arrival), load, LEN(load), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int k = 3, arrival[] = { 1, 2, 3, 4 }, load[] = { 1, 2, 1, 2 };
    int len, target[] = { 0 };
    int *ans = busiestServers(k, arrival, LEN(arrival), load, LEN(load), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int k = 3, arrival[] = { 1, 2, 3 }, load[] = { 10, 12, 11 };
    int len, target[] = { 0, 1, 2 };
    int *ans = busiestServers(k, arrival, LEN(arrival), load, LEN(load), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_4) {
    int k = 3, arrival[] = { 1, 2, 3, 4, 8, 9, 10 }, load[] = { 5, 2, 10, 3, 1, 2, 2 };
    int len, target[] = { 1 };
    int *ans = busiestServers(k, arrival, LEN(arrival), load, LEN(load), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_5) {
    int k = 1, arrival[] = { 1 }, load[] = { 1 };
    int len, target[] = { 0 };
    int *ans = busiestServers(k, arrival, LEN(arrival), load, LEN(load), &len);

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
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}