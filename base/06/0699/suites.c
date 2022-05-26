/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/26 上午10:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0699.c"

START_TEST(test_official_1) {
    int *positions[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 6, 1 } };
    int target[]     = { 2, 5, 5 };
    int len, *ans = fallingSquares(positions, LEN(positions), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int *positions[] = { (int[]) { 100, 100 }, (int[]) { 200, 100 } };
    int target[]     = { 100, 100 };
    int len, *ans = fallingSquares(positions, LEN(positions), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}