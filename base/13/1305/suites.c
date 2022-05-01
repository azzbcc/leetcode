/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/1 下午1:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "1305.c"

START_TEST(test_official_1) {
    int root1[] = { 2, 1, 4 }, root2[] = { 1, 0, 3 };
    tree_t t1 = tree_create(root1), t2 = tree_create(root2);

    int target[] = { 0, 1, 1, 2, 3, 4 };
    int len, *ans = getAllElements(t1, t2, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    tree_free(t1), tree_free(t2);
    free(ans);
}

START_TEST(test_official_2) {
    int root1[] = { 1, null, 8 }, root2[] = { 8, 1 };
    tree_t t1 = tree_create(root1), t2 = tree_create(root2);

    int target[] = { 1, 1, 8, 8 };
    int len, *ans = getAllElements(t1, t2, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    tree_free(t1), tree_free(t2);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}