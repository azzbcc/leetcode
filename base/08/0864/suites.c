/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/10 上午10:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0864.c"

START_TEST(test_official_1) {
    char *grid[] = { "@.a.#", "###.#", "b.A.B" };
    int target = 8, ans = shortestPathAllKeys(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *grid[] = { "@..aA", "..B#.", "....b" };
    int target = 6, ans = shortestPathAllKeys(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *grid[] = { "@Aa" };
    int target = -1, ans = shortestPathAllKeys(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}