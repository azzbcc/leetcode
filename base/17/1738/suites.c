/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/19 下午2:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1738.c"

START_TEST(test_official_1) {
    int col = 2, k = 1;
    int *matrix[] = { (int[]) { 5, 2 }, (int[]) { 1, 6 } };
    int target = 7, ans = kthLargestValue(matrix, LEN(matrix), &col, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col = 2, k = 2;
    int *matrix[] = { (int[]) { 5, 2 }, (int[]) { 1, 6 } };
    int target = 5, ans = kthLargestValue(matrix, LEN(matrix), &col, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int col = 2, k = 3;
    int *matrix[] = { (int[]) { 5, 2 }, (int[]) { 1, 6 } };
    int target = 4, ans = kthLargestValue(matrix, LEN(matrix), &col, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int col = 2, k = 4;
    int *matrix[] = { (int[]) { 5, 2 }, (int[]) { 1, 6 } };
    int target = 0, ans = kthLargestValue(matrix, LEN(matrix), &col, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
    int col = 1000, k = 114257;
#include "tle.c"
    int target = 14, ans = kthLargestValue(matrix, LEN(matrix), &col, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}