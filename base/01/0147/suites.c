/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/21 下午8:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0147.c"

START_TEST(test_official_1) {
    int arr[] = { 4, 2, 1, 3 }, target[] = { 1, 2, 3, 4 };

    list_t la = list_create(arr), lt = list_create(target);

    list_t ans = insertionSortList(la);

    ck_assert(list_equal(ans, lt));

    list_free(lt);
    list_free(ans);
}

START_TEST(test_official_2) {
    int arr[] = { -1, 5, 3, 4, 0 }, target[] = { -1, 0, 3, 4, 5 };

    list_t la = list_create(arr), lt = list_create(target);

    list_t ans = insertionSortList(la);

    ck_assert(list_equal(ans, lt));

    list_free(lt);
    list_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}