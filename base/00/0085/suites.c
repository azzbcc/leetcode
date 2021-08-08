/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/26 下午1:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0085.c"

START_TEST(test_official_1) {
    char *matrix[] = { "10100", "10111", "11111", "10010" };

    int len    = strlen(matrix[0]);
    int target = 6, ans = maximalRectangle(matrix, LEN(matrix), &len);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *matrix[] = {};

    int len    = 0;
    int target = 0, ans = maximalRectangle(matrix, LEN(matrix), &len);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *matrix[] = { "0" };

    int len    = strlen(matrix[0]);
    int target = 0, ans = maximalRectangle(matrix, LEN(matrix), &len);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *matrix[] = { "1" };

    int len    = strlen(matrix[0]);
    int target = 1, ans = maximalRectangle(matrix, LEN(matrix), &len);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    char *matrix[] = { "00" };

    int len    = strlen(matrix[0]);
    int target = 0, ans = maximalRectangle(matrix, LEN(matrix), &len);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *matrix[] = { "000", "000", "111" };

    int len    = strlen(matrix[0]);
    int target = 3, ans = maximalRectangle(matrix, LEN(matrix), &len);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}