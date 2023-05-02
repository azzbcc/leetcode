/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/2 13:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0970.c"

static int array_comp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}

START_TEST(test_official_1) {
    int x = 2, y = 3, bound = 10;
    int target[] = { 2, 3, 4, 5, 7, 9, 10 };
    int len, *ans = powerfulIntegers(x, y, bound, &len);
    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int x = 3, y = 5, bound = 15;
    int target[] = { 2, 4, 6, 8, 10, 14 };
    int len, *ans = powerfulIntegers(x, y, bound, &len);
    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}