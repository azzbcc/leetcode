/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/4 11:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <tree.h>
#include <common.h>

#include "0449.c"

START_TEST(test_official_1) {
    int arr[]     = { 2, 1, 3 };
    tree_t root   = tree_create(arr);
    char *help    = serialize(root);
    tree_t target = deserialize(help);

    ck_assert(tree_equal(root, target));
    tree_free(target);
    tree_free(root);
    free(help);
}

START_TEST(test_official_2) {
    int arr[]     = {};
    tree_t root   = tree_create(arr);
    char *help    = serialize(root);
    tree_t target = deserialize(help);

    ck_assert(tree_equal(root, target));
    tree_free(target);
    tree_free(root);
    free(help);
}

START_TEST(test_limit) {
#include "limit.c"
    tree_t root   = tree_create(arr);
    char *help    = serialize(root);
    tree_t target = deserialize(help);

    ck_assert(tree_equal(root, target));
    tree_free(target);
    tree_free(root);
    free(help);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}