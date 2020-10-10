/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/23 上午11:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0617.c"

START_TEST(test_official) {
    int arr1[] = { 1, 3, 2, 5 }, arr2[] = { 2, 1, 3, null, 4, null, 7 };
    int target[] = { 3, 4, 5, 5, 4, null, 7 };

    tree_t t1 = tree_create(arr1);
    tree_t t2 = tree_create(arr2);
    tree_t tt = tree_create(target);

    tree_t ans = mergeTrees(t1, t2);
    ck_assert(tree_equal(tt, ans));

    tree_free(t1);
    tree_free(t2);
    tree_free(tt);
    tree_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}
