/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/16 下午1:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0803.c"

START_TEST(test_official_1) {
    int col[] = { 4, 4 }, *grid[] = { (int[]) { 1, 0, 0, 0 }, (int[]) { 1, 1, 1, 0 } };
    int len, *hits[] = { (int[]) { 1, 0 } }, target[] = { 2 };
    int *ans = hitBricks(grid, LEN(grid), col, hits, LEN(hits), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int col[] = { 4, 4 }, *grid[] = { (int[]) { 1, 0, 0, 0 }, (int[]) { 1, 1, 0, 0 } };
    int len, *hits[] = { (int[]) { 1, 1 }, (int[]) { 1, 0 } }, target[] = { 0, 0 };
    int *ans = hitBricks(grid, LEN(grid), col, hits, LEN(hits), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_failed) {
    int col[] = { 1 }, *grid[] = { (int[]) { 1 }, (int[]) { 1 }, (int[]) { 1 }, (int[]) { 1 }, (int[]) { 1 } };
    int *hits[] = { (int[]) { 3, 0 }, (int[]) { 4, 0 }, (int[]) { 1, 0 }, (int[]) { 2, 0 }, (int[]) { 0, 0 } };
    int len, target[] = { 1, 0, 1, 0, 0 };
    int *ans = hitBricks(grid, LEN(grid), col, hits, LEN(hits), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}