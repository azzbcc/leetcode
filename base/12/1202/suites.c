/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/11 下午12:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1202.c"

START_TEST(test_official_1) {
    int arr[][2] = { { 0, 3 }, { 1, 2 } };
    int *grid[]  = { arr[0], arr[1] };
    char s[] = "dcab", *target = "bacd", *ans = smallestStringWithSwaps(s, grid, LEN(grid), NULL);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[][2] = { { 0, 3 }, { 1, 2 }, { 0, 2 } };
    int *grid[]  = { arr[0], arr[1], arr[2] };
    char s[] = "dcab", *target = "abcd", *ans = smallestStringWithSwaps(s, grid, LEN(grid), NULL);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[][2] = { { 0, 1 }, { 1, 2 } };
    int *grid[]  = { arr[0], arr[1] };
    char s[] = "cba", *target = "abc", *ans = smallestStringWithSwaps(s, grid, LEN(grid), NULL);

    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}