/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/1 下午2:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "1080.c"

START_TEST(test_official_1) {
    int limit    = 1;
    int root[]   = { 1, 2, 3, 4, -99, -99, 7, 8, 9, -99, -99, 12, 13, -99, 14 };
    int target[] = { 1, 2, 3, 4, null, null, 7, 8, 9, null, 14 };
    tree_t ta = tree_create(root), tt = tree_create(target);

    tree_t ans = sufficientSubset(ta, limit);
    ck_assert(tree_equal(ans, tt));

    tree_free(ans);
    tree_free(tt);
}

START_TEST(test_official_2) {
    int limit    = 22;
    int root[]   = { 5, 4, 8, 11, null, 17, 4, 7, 1, null, null, 5, 3 };
    int target[] = { 5, 4, 8, 11, null, 17, 4, 7, null, null, null, 5 };
    tree_t ta = tree_create(root), tt = tree_create(target);

    tree_t ans = sufficientSubset(ta, limit);
    ck_assert(tree_equal(ans, tt));

    tree_free(ans);
    tree_free(tt);
}

START_TEST(test_official_3) {
    int limit    = 0;
    int root[]   = { 5, -6, -6 };
    int target[] = {};
    tree_t ta = tree_create(root), tt = tree_create(target);

    tree_t ans = sufficientSubset(ta, limit);
    ck_assert(tree_equal(ans, tt));

    tree_free(ans);
    tree_free(tt);
}

START_TEST(test_failed) {
    int limit    = -1;
    int root[]   = { 1, 2, -3, -5, null, 4, null };
    int target[] = { 1, null, -3, 4 };
    tree_t ta = tree_create(root), tt = tree_create(target);

    tree_t ans = sufficientSubset(ta, limit);
    ck_assert(tree_equal(ans, tt));

    tree_free(ans);
    tree_free(tt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}