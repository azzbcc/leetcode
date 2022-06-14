/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/14 上午11:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0498.c"

START_TEST(test_official_1) {
    int col = 3, *mat[] = { (int[]) { 1, 2, 3 }, (int[]) { 4, 5, 6 }, (int[]) { 7, 8, 9 } };
    int target[] = { 1, 2, 4, 7, 5, 3, 6, 8, 9 };
    int len, *ans = findDiagonalOrder(mat, LEN(mat), &col, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int col = 2, *mat[] = { (int[]) { 1, 2 }, (int[]) { 3, 4 } };
    int target[] = { 1, 2, 3, 4 };
    int len, *ans = findDiagonalOrder(mat, LEN(mat), &col, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_own) {
    int col = 4, *mat[] = { (int[]) { 1, 2, 3, 4 }, (int[]) { 5, 6, 7, 8 } };
    int target[] = { 1, 2, 5, 6, 3, 4, 7, 8 };
    int len, *ans = findDiagonalOrder(mat, LEN(mat), &col, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}