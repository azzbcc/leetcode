/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/12 上午9:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>
#include <tree.h>

#include "1367.c"

START_TEST(test_next) {
    int la[]     = { 1, 2, 1, 2, 1, 2, 3, 1 };
    int target[] = { -1, 0, 0, 1, 2, 3, 4, 0 };
    list_t l     = list_create(la);

    init(l);
    ck_assert_mem_eq(next, target, sizeof(target));

    list_free(l);
}

START_TEST(test_official_1) {
    int la[] = { 4, 2, 8 }, ta[] = { 1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3 };
    list_t l = list_create(la);
    tree_t t = tree_create(ta);

    bool target = true, ans = isSubPath(l, t);
    ck_assert_int_eq(ans, target);

    list_free(l);
    tree_free(t);
}

START_TEST(test_official_2) {
    int la[] = { 1, 4, 2, 6 }, ta[] = { 1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3 };
    list_t l = list_create(la);
    tree_t t = tree_create(ta);

    bool target = true, ans = isSubPath(l, t);
    ck_assert_int_eq(ans, target);

    list_free(l);
    tree_free(t);
}

START_TEST(test_official_3) {
    int la[] = { 1, 4, 2, 6, 8 }, ta[] = { 1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3 };
    list_t l = list_create(la);
    tree_t t = tree_create(ta);

    bool target = false, ans = isSubPath(l, t);
    ck_assert_int_eq(ans, target);

    list_free(l);
    tree_free(t);
}

START_TEST(test_failed) {
    int la[] = { 2, 2, 1 }, ta[] = { 2, null, 2, null, 2, null, 1 };
    list_t l = list_create(la);
    tree_t t = tree_create(ta);

    tree_print(t);

    bool target = true, ans = isSubPath(l, t);
    ck_assert_int_eq(ans, target);

    list_free(l);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_next);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}