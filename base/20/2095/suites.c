/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/6 下午5:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "2095.c"

START_TEST(test_official_1) {
    int arr[]    = { 1, 3, 4, 7, 1, 2, 6 };
    int target[] = { 1, 3, 4, 1, 2, 6 };

    list_t lt = list_create(target);
    list_t la = deleteMiddle(list_create(arr));

    ck_assert(list_equal(la, lt));

    list_free(la);
    list_free(lt);
}

START_TEST(test_official_2) {
    int arr[]    = { 1, 2, 3, 4 };
    int target[] = { 1, 2, 4 };

    list_t lt = list_create(target);
    list_t la = deleteMiddle(list_create(arr));

    ck_assert(list_equal(la, lt));

    list_free(la);
    list_free(lt);
}

START_TEST(test_official_3) {
    int arr[]    = { 2, 1 };
    int target[] = { 2 };

    list_t lt = list_create(target);
    list_t la = deleteMiddle(list_create(arr));

    ck_assert(list_equal(la, lt));

    list_free(la);
    list_free(lt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}