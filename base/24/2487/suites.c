/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/3 08:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "2487.c"

START_TEST(test_official_1) {
    int arr[] = { 5, 2, 13, 3, 8 }, t[] = { 13, 8 };
    list_t l = list_create(arr), target = list_create(t);
    list_t ans = removeNodes(l);
    ck_assert(list_equal(ans, target));
    list_free(ans);
    list_free(target);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 1, 1, 1 }, t[] = { 1, 1, 1, 1 };
    list_t l = list_create(arr), target = list_create(t);
    list_t ans = removeNodes(l);
    ck_assert(list_equal(ans, target));
    list_free(ans);
    list_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}