/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/3 下午1:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0095.c"

START_TEST(test_official) {
    int len, target[][5] = { { 1, null, 2, null, 3 },
                             { 1, null, 3, 2, null },
                             { 2, 1, 3, null, null },
                             { 3, 1, null, null, 2 },
                             { 3, 2, null, 1, null } };
    tree_t *ans = generateTrees(3, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        tree_t t = tree_create(target[i]);
        ck_assert(tree_equal(t, ans[i]));
        tree_free(ans[i]);
        tree_free(t);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len, target[][9] = { { 1, null, 2, null, 3, null, 4, null, 5 }, { 1, null, 2, null, 3, null, 5, 4, null },
                             { 1, null, 2, null, 4, 3, 5, null, null }, { 1, null, 2, null, 5, 3, null, null, 4 },
                             { 1, null, 2, null, 5, 4, null, 3, null }, { 1, null, 3, 2, 4, null, null, null, 5 },
                             { 1, null, 3, 2, 5, null, null, 4, null }, { 1, null, 4, 2, 5, null, 3, null, null },
                             { 1, null, 4, 3, 5, 2, null, null, null }, { 1, null, 5, 2, null, null, 3, null, 4 },
                             { 1, null, 5, 2, null, null, 4, 3, null }, { 1, null, 5, 3, null, 2, 4, null, null },
                             { 1, null, 5, 4, null, 2, null, null, 3 }, { 1, null, 5, 4, null, 3, null, 2, null },
                             { 2, 1, 3, null, null, null, 4, null, 5 }, { 2, 1, 3, null, null, null, 5, 4, null },
                             { 2, 1, 4, null, null, 3, 5, null, null }, { 2, 1, 5, null, null, 3, null, null, 4 },
                             { 2, 1, 5, null, null, 4, null, 3, null }, { 3, 1, 4, null, 2, null, 5, null, null },
                             { 3, 1, 5, null, 2, 4, null, null, null }, { 3, 2, 4, 1, null, null, 5, null, null },
                             { 3, 2, 5, 1, null, 4, null, null, null }, { 4, 1, 5, null, 2, null, null, null, 3 },
                             { 4, 1, 5, null, 3, null, null, 2, null }, { 4, 2, 5, 1, 3, null, null, null, null },
                             { 4, 3, 5, 1, null, null, null, null, 2 }, { 4, 3, 5, 2, null, null, null, 1, null },
                             { 5, 1, null, null, 2, null, 3, null, 4 }, { 5, 1, null, null, 2, null, 4, 3, null },
                             { 5, 1, null, null, 3, 2, 4, null, null }, { 5, 1, null, null, 4, 2, null, null, 3 },
                             { 5, 1, null, null, 4, 3, null, 2, null }, { 5, 2, null, 1, 3, null, null, null, 4 },
                             { 5, 2, null, 1, 4, null, null, 3, null }, { 5, 3, null, 1, 4, null, 2, null, null },
                             { 5, 3, null, 2, 4, 1, null, null, null }, { 5, 4, null, 1, null, null, 2, null, 3 },
                             { 5, 4, null, 1, null, null, 3, 2, null }, { 5, 4, null, 2, null, 1, 3, null, null },
                             { 5, 4, null, 3, null, 1, null, null, 2 }, { 5, 4, null, 3, null, 2, null, 1, null } };
    tree_t *ans = generateTrees(5, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        tree_t t = tree_create(target[i]);
        ck_assert(tree_equal(t, ans[i]));
        tree_free(ans[i]);
        tree_free(t);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}
