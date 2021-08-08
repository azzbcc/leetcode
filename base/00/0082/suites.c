/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/25 下午1:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0082.c"

START_TEST(test_official_1) {
    int arr[]    = { 1, 2, 3, 3, 4, 4, 5 };
    int target[] = { 1, 2, 5 };

    list_t la = list_create(arr);
    list_t lt = list_create(target);

    list_t ans = deleteDuplicates(la);
    ck_assert(list_equal(ans, lt));

    list_free(ans), list_free(lt);
}

START_TEST(test_official_2) {
    int arr[]    = { 1, 1, 1, 2, 3 };
    int target[] = { 2, 3 };

    list_t la = list_create(arr);
    list_t lt = list_create(target);

    list_t ans = deleteDuplicates(la);
    ck_assert(list_equal(ans, lt));

    list_free(ans), list_free(lt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}
