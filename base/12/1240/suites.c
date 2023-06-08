/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/8 15:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1240.c"

START_TEST(test_official_1) {
    int n = 2, m = 3;
    int target = 3, ans = tilingRectangle(n, m);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 5, m = 8;
    int target = 5, ans = tilingRectangle(n, m);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 11, m = 13;
    int target = 6, ans = tilingRectangle(n, m);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int test[13][13] = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 }, { 2, 1, 3, 2, 4, 3, 5, 4, 6, 5, 7, 6, 8 },
                         { 3, 3, 1, 4, 4, 2, 5, 5, 3, 6, 6, 4, 7 },     { 4, 2, 4, 1, 5, 3, 5, 2, 6, 4, 6, 3, 7 },
                         { 5, 4, 4, 5, 1, 5, 5, 5, 6, 2, 6, 6, 6 },     { 6, 3, 2, 3, 5, 1, 5, 4, 3, 4, 6, 2, 6 },
                         { 7, 5, 5, 5, 5, 5, 1, 7, 6, 6, 6, 6, 6 },     { 8, 4, 5, 2, 5, 4, 7, 1, 7, 5, 6, 3, 6 },
                         { 9, 6, 3, 6, 6, 3, 6, 7, 1, 6, 7, 4, 7 },     { 10, 5, 6, 4, 2, 4, 6, 5, 6, 1, 6, 5, 7 },
                         { 11, 7, 6, 6, 6, 6, 6, 6, 7, 6, 1, 7, 6 },    { 12, 6, 4, 3, 6, 2, 6, 3, 4, 5, 7, 1, 7 },
                         { 13, 8, 7, 7, 6, 6, 6, 6, 7, 7, 6, 7, 1 } };
    for (int n = 1; n <= 13; ++n) {
        for (int m = 1; m <= 13; ++m) {
            ck_assert_int_eq(test[n - 1][m - 1], tilingRectangle(n, m));
        }
    }
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}