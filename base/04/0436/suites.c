/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/20 上午11:30
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0436.c"

START_TEST(test_official_1) {
    int *intervals[] = { (int[]) { 1, 2 } };
    int target[]     = { -1 };
    int len, *ans = findRightInterval(intervals, LEN(intervals), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int *intervals[] = { (int[]) { 3, 4 }, (int[]) { 2, 3 }, (int[]) { 1, 2 } };
    int target[]     = { -1, 0, 1 };
    int len, *ans = findRightInterval(intervals, LEN(intervals), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int *intervals[] = { (int[]) { 1, 4 }, (int[]) { 2, 3 }, (int[]) { 3, 4 } };
    int target[]     = { -1, 2, -1 };
    int len, *ans = findRightInterval(intervals, LEN(intervals), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}