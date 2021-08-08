/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/27 下午2:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0061.c"

START_TEST(test_official_1) {
    int arr[]    = { 1, 2, 3, 4, 5 };
    int target[] = { 4, 5, 1, 2, 3 };

    list_t la = list_create(arr);
    list_t lt = list_create(target);

    list_t ans = rotateRight(la, 2);
    ck_assert(list_equal(ans, lt));

    list_free(ans), list_free(lt);
}

START_TEST(test_official_2) {
    int arr[]    = { 0, 1, 2 };
    int target[] = { 2, 0, 1 };

    list_t la = list_create(arr);
    list_t lt = list_create(target);

    list_t ans = rotateRight(la, 4);
    ck_assert(list_equal(ans, lt));

    list_free(ans), list_free(lt);
}

START_TEST(test_failed) {
    int arr[]    = {};
    int target[] = {};

    list_t la = list_create(arr);
    list_t lt = list_create(target);

    list_t ans = rotateRight(la, 0);
    ck_assert(list_equal(ans, lt));

    list_free(ans), list_free(lt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}