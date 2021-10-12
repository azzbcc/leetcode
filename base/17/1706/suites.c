/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/12 下午4:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1706.c"

START_TEST(test_official_1) {
    int col      = 5;
    int *grid[]  = { (int[]) { 1, 1, 1, -1, -1 }, (int[]) { 1, 1, 1, -1, -1 }, (int[]) { -1, -1, -1, 1, 1 },
                    (int[]) { 1, 1, 1, 1, -1 }, (int[]) { -1, -1, -1, -1, -1 } };
    int target[] = { 1, -1, -1, -1, -1 };
    int len, *ans = findBall(grid, LEN(grid), &col, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int col      = 1;
    int *grid[]  = { (int[]) { -1 } };
    int target[] = { -1 };
    int len, *ans = findBall(grid, LEN(grid), &col, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_3) {
    int col      = 6;
    int *grid[]  = { (int[]) { 1, 1, 1, 1, 1, 1 }, (int[]) { -1, -1, -1, -1, -1, -1 }, (int[]) { 1, 1, 1, 1, 1, 1 },
                    (int[]) { -1, -1, -1, -1, -1, -1 } };
    int target[] = { 0, 1, 2, 3, 4, -1 };
    int len, *ans = findBall(grid, LEN(grid), &col, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}