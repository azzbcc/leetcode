/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/8 上午10:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2055.c"

START_TEST(test_official_1) {
    char *s        = "**|**|***|";
    int *queries[] = { (int[]) { 2, 5 }, (int[]) { 5, 9 } };
    int target[]   = { 2, 3 };
    int len, *ans = platesBetweenCandles(s, queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    char *s        = "***|**|*****|**||**|*";
    int *queries[] = { (int[]) { 1, 17 }, (int[]) { 4, 5 }, (int[]) { 14, 17 }, (int[]) { 5, 11 }, (int[]) { 15, 16 } };
    int target[]   = { 9, 0, 0, 0, 0 };
    int len, *ans = platesBetweenCandles(s, queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}