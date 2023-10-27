/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/27 09:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1465.c"

START_TEST(test_official_1) {
    int h = 5, w = 4, horizontalCuts[] = { 1, 2, 4 }, verticalCuts[] = { 1, 3 };
    int target = 4, ans = maxArea(h, w, horizontalCuts, LEN(horizontalCuts), verticalCuts, LEN(verticalCuts));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int h = 5, w = 4, horizontalCuts[] = { 3, 1 }, verticalCuts[] = { 1 };
    int target = 6, ans = maxArea(h, w, horizontalCuts, LEN(horizontalCuts), verticalCuts, LEN(verticalCuts));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int h = 5, w = 4, horizontalCuts[] = { 3 }, verticalCuts[] = { 3 };
    int target = 9, ans = maxArea(h, w, horizontalCuts, LEN(horizontalCuts), verticalCuts, LEN(verticalCuts));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}