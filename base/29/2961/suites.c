/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/25 14:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2961.c"

START_TEST(test_official_1) {
    int *variables[] = { (int[]) { 2, 3, 3, 10 }, (int[]) { 3, 3, 3, 1 }, (int[]) { 6, 1, 1, 4 } }, t = 2;
    int len, target[] = { 0, 2 }, *ans = getGoodIndices(variables, LEN(variables), NULL, t, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int *variables[] = { (int[]) { 39, 3, 1000, 1000 } }, t = 17;
    int len, target[] = {}, *ans = getGoodIndices(variables, LEN(variables), NULL, t, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}