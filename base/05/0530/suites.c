/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/12 上午11:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0530.c"

START_TEST(test_official) {
    tree_t t = tree_create(((int[]) {1, null, 3, 2}));

    int target = 1, ans = getMinimumDifference(t);

    ck_assert_int_eq(target, ans);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}