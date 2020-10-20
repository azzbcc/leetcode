/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/20 上午12:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0143.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 4 }, target[] = { 1, 4, 2, 3 };

    list_t la = list_create(arr), lt = list_create(target);

    reorderList(la);

    ck_assert(list_equal(la, lt));

    list_free(la);
    list_free(lt);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2, 3, 4, 5 }, target[] = { 1, 5, 2, 4, 3 };

    list_t la = list_create(arr), lt = list_create(target);

    reorderList(la);

    ck_assert(list_equal(la, lt));

    list_free(la);
    list_free(lt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}