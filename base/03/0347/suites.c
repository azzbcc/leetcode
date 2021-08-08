/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/7 上午11:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0347.c"

static int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}

START_TEST(test_official_1) {
    int len, k = 2, arr[] = { 1, 1, 1, 2, 2, 3 };
    int target[] = { 1, 2 }, *ans = topKFrequent(arr, sizeof(arr) / sizeof(arr[0]), k, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(int), cmp);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int len, k = 1, arr[] = { 1 };
    int target[] = { 1 }, *ans = topKFrequent(arr, sizeof(arr) / sizeof(arr[0]), k, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(int), cmp);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_failed) {
    int len, k = 10, arr[] = { 3, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6 };
    int target[] = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 11 }, *ans = topKFrequent(arr, sizeof(arr) / sizeof(arr[0]), k, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(int), cmp);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}