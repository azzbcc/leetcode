/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/15 上午10:57
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1380.c"

START_TEST(test_official_1) {
    int len, col = 3;
    int *matrix[] = { (int[]) { 3, 7, 8 }, (int[]) { 9, 11, 13 }, (int[]) { 15, 16, 17 } };
    int target[]  = { 15 };
    int *ans      = luckyNumbers(matrix, LEN(matrix), &col, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len, col = 4;
    int *matrix[] = { (int[]) { 1, 10, 4, 2 }, (int[]) { 9, 3, 8, 7 }, (int[]) { 15, 16, 17, 12 } };
    int target[]  = { 12 };
    int *ans      = luckyNumbers(matrix, LEN(matrix), &col, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int len, col = 2;
    int *matrix[] = { (int[]) { 7, 8 }, (int[]) { 1, 2 } };
    int target[]  = { 7 };
    int *ans      = luckyNumbers(matrix, LEN(matrix), &col, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}