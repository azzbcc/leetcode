/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/3 上午10:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "17_04.c"

int array_cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
START_TEST(test_official) {
    int k = 4, arr[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
    int target[] = { 1, 2, 3, 4 };
    int len, *ans = smallestK(arr, LEN(arr), k, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), array_cmp);
    qsort(target, len, sizeof(int), array_cmp);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_failed_1) {
    int k = 0, arr[] = {};
    int target[] = {};
    int len, *ans = smallestK(arr, LEN(arr), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_failed_2) {
    int k = 0, arr[] = { 1, 2, 3 };
    int target[] = {};
    int len, *ans = smallestK(arr, LEN(arr), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_official);
}