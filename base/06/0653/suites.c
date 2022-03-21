/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/21 上午11:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0653.c"

START_TEST(test_official_1) {
    int root[] = { 5, 3, 6, 2, 4, null, 7 }, k = 9;
    tree_t t = tree_create(root);
    ck_assert_int_eq(findTarget(t, k), true);
    tree_free(t);
}

START_TEST(test_official_2) {
    int root[] = { 5, 3, 6, 2, 4, null, 7 }, k = 28;
    tree_t t = tree_create(root);
    ck_assert_int_eq(findTarget(t, k), false);
    tree_free(t);
}

START_TEST(test_failed) {
    int root[] = { 2, 0, 3, -4, 1 }, k = -1;
    tree_t t = tree_create(root);
    ck_assert_int_eq(findTarget(t, k), true);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}