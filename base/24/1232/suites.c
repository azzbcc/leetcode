/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/17 上午1:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1232.c"

START_TEST(test_official_1) {
    int *arr[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 3, 4 },
                   (int[]) { 4, 5 }, (int[]) { 5, 6 }, (int[]) { 6, 7 } };

    bool target = true, ans = checkStraightLine(arr, LEN(arr), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *arr[] = { (int[]) { 1, 1 }, (int[]) { 2, 2 }, (int[]) { 3, 4 },
                   (int[]) { 4, 5 }, (int[]) { 5, 6 }, (int[]) { 7, 7 } };

    bool target = false, ans = checkStraightLine(arr, LEN(arr), NULL);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}
