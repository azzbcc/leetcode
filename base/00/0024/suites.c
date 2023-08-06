/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/10 下午3:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0024.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 4 }, arr_target[] = { 2, 1, 4, 3 };

    list_t l = list_create(arr), target = list_create(arr_target);
    list_t ans = swapPairs(l);

    ck_assert(list_equal(ans, target));

    list_free(target);
    list_free(ans);
}

START_TEST(test_official_2) {
    int arr[] = {}, arr_target[] = {};

    list_t l = list_create(arr), target = list_create(arr_target);
    list_t ans = swapPairs(l);

    ck_assert(list_equal(ans, target));

    list_free(target);
    list_free(ans);
}

START_TEST(test_official_3) {
    int arr[] = { 1 }, arr_target[] = { 1 };

    list_t l = list_create(arr), target = list_create(arr_target);
    list_t ans = swapPairs(l);

    ck_assert(list_equal(ans, target));

    list_free(target);
    list_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}