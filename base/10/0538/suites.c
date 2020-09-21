/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/21 上午11:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0538.c"

START_TEST(test_official) {
    tree_t ta     = tree_create((int[]) { 5, 2, 13 }, 3);
    tree_t target = tree_create((int[]) { 18, 20, 13 }, 3);

    tree_t ans = convertBST(ta);

    ck_assert(tree_equal(target, ans));

    tree_free(ans);
    tree_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}