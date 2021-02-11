/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/11 下午10:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "1110.c"

START_TEST(test_official) {
    int len, arr[] = { 1, 2, 3, 4, 5, 6, 7 }, to_delete[] = { 3, 5 };
    int *tar[] = { (int[]) { 1, 2, null, 4 }, (int[]) { 6 }, (int[]) { 7 } }, col[] = { 4, 1, 1 };
    tree_t target[LEN(tar)];
    for (int i = 0; i < LEN(tar); ++i) {
        target[i] = tree_create_size(tar[i], col[i]);
    }
    tree_t *ans = delNodes(tree_create(arr), to_delete, LEN(to_delete), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert(tree_equal(target[i], ans[i]));
        tree_free(ans[i]);
        tree_free(target[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}