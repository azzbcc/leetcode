/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/12 上午8:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0806.c"

START_TEST(test_official_1) {
    int widths[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    char *S      = "abcdefghijklmnopqrstuvwxyz";
    int target[] = { 3, 60 };
    int len, *ans = numberOfLines(widths, LEN(widths), S, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int widths[] = { 4,  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    char *S      = "bbbcccdddaaa";
    int target[] = { 2, 4 };
    int len, *ans = numberOfLines(widths, LEN(widths), S, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}