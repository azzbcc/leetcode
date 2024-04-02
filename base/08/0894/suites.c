/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/2 10:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0894.c"

typedef struct {
    tree_t node;
    UT_hash_handle hh;
} *hash_t;
START_TEST(test_official_1) {
    int len, n = 7, col[] = { 11, 9, 7, 11, 9 };
    int target[][0xff] = { { 0, 0, 0, null, null, 0, 0, null, null, 0, 0 },
                           { 0, 0, 0, null, null, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, null, null, null, null, 0, 0 },
                           { 0, 0, 0, 0, 0, null, null, 0, 0 } };
    tree_t tmp, *ans = allPossibleFBT(n, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        tmp = tree_create_size(target[i], col[i]);
        ck_assert(tree_equal(tmp, ans[i]));
        tree_free(tmp);
        tree_free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len, n = 3, col[] = { 3 };
    int target[][0xff] = { { 0, 0, 0 } };
    tree_t tmp, *ans = allPossibleFBT(n, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        tmp = tree_create_size(target[i], col[i]);
        ck_assert(tree_equal(tmp, ans[i]));
        tree_free(tmp);
        tree_free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}