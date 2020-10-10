/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/28 上午11:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0104.c"

START_TEST(test_official) {
    int arr[] = { 3, 9, 20, null, null, 15, 7 }, target = 3;
    tree_t tree = tree_create(arr);

    int depth = maxDepth(tree);
    ck_assert_msg(depth == target, "error, except %d but got %d on maxDepth(3, 9, 20, null, null, 15, 7).", target,
                  depth);

    tree_free(tree);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}
