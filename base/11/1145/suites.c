/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/3 下午3:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "1145.c"

START_TEST(test_official_1) {
    int root[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, n = 11, x = 3;
    tree_t t = tree_create(root);

    ck_assert_int_eq(true, btreeGameWinningMove(t, n, x));
    tree_free(t);
}

START_TEST(test_official_2) {
    int root[] = { 1, 2, 3 }, n = 3, x = 1;
    tree_t t = tree_create(root);

    ck_assert_int_eq(false, btreeGameWinningMove(t, n, x));
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}