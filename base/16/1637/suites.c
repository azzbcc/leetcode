/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/30 下午2:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1637.c"

START_TEST(test_official_1) {
    int *points[] = { (int[]) { 8, 7 }, (int[]) { 9, 9 }, (int[]) { 7, 4 }, (int[]) { 9, 7 } };
    int target = 1, ans = maxWidthOfVerticalArea(points, LEN(points), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *points[] = { (int[]) { 3, 1 }, (int[]) { 9, 0 }, (int[]) { 1, 0 },
                      (int[]) { 1, 4 }, (int[]) { 5, 3 }, (int[]) { 8, 8 } };
    int target = 3, ans = maxWidthOfVerticalArea(points, LEN(points), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}