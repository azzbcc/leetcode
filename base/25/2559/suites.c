/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/2 14:22
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2559.c"

START_TEST(test_official_1) {
    char *words[]  = { "aba", "bcb", "ece", "aa", "e" };
    int *queries[] = { (int[]) { 0, 2 }, (int[]) { 1, 4 }, (int[]) { 1, 1 } };
    int target[]   = { 2, 3, 0 };
    int len, *ans = vowelStrings(words, LEN(words), queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(ans));
    free(ans);
}

START_TEST(test_official_2) {
    char *words[]  = { "a", "e", "i" };
    int *queries[] = { (int[]) { 0, 2 }, (int[]) { 0, 1 }, (int[]) { 2, 2 } };
    int target[]   = { 3, 2, 1 };
    int len, *ans = vowelStrings(words, LEN(words), queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(ans));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}