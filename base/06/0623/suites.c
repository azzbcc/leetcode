/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/5 上午8:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0623.c"

START_TEST(test_official_1) {
    int val = 1, depth = 2;
    int arr[]    = { 4, 2, 6, 3, 1, 5 };
    int target[] = { 4, 1, 1, 2, null, null, 6, 3, 1, 5 };

    tree_t pa = tree_create(arr), pt = tree_create(target);

    tree_t ans = addOneRow(pa, val, depth);
    ck_assert(tree_equal(ans, pa));

    tree_free(ans);
    tree_free(pt);
}

START_TEST(test_official_2) {
    int val = 1, depth = 3;
    int arr[]    = { 4, 2, null, 3, 1 };
    int target[] = { 4, 2, null, 1, 1, 3, null, null, 1 };

    tree_t pa = tree_create(arr), pt = tree_create(target);

    tree_t ans = addOneRow(pa, val, depth);
    ck_assert(tree_equal(ans, pt));

    tree_free(ans);
    tree_free(pt);
}

START_TEST(test_failed_1) {
    int val = 5, depth = 4;
    int arr[]    = { 1, 2, 3, 4 };
    int target[] = { 1, 2, 3, 4, null, null, null, 5, 5 };

    tree_t pa = tree_create(arr), pt = tree_create(target);

    tree_t ans = addOneRow(pa, val, depth);
    ck_assert(tree_equal(ans, pt));

    tree_free(ans);
    tree_free(pt);
}

START_TEST(test_failed_2) {
    int val = 1, depth = 4;
    int arr[]    = { 5, 3, null, 4, 2, null, 1 };
    int target[] = { 5, 3, null, 4, 2, 1, 1, 1, 1, null, null, null, 1 };

    tree_t pa = tree_create(arr), pt = tree_create(target);

    tree_t ans = addOneRow(pa, val, depth);
    ck_assert(tree_equal(ans, pt));

    tree_free(ans);
    tree_free(pt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}