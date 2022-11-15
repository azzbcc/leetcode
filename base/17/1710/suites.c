/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/15 下午1:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1710.c"

START_TEST(test_official_1) {
    int *boxTypes[] = { (int[]) { 1, 3 }, (int[]) { 2, 2 }, (int[]) { 3, 1 } };
    int truckSize = 4, target = 8;
    int ans = maximumUnits(boxTypes, LEN(boxTypes), NULL, truckSize);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *boxTypes[] = { (int[]) { 5, 10 }, (int[]) { 2, 5 }, (int[]) { 4, 7 }, (int[]) { 3, 9 } };
    int truckSize = 10, target = 91;
    int ans = maximumUnits(boxTypes, LEN(boxTypes), NULL, truckSize);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}