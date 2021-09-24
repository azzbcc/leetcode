/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/24 下午2:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "offer_18.c"

START_TEST(test_official_1) {
    int arr[] = { 4, 5, 1, 9 }, val = 5;
    int target[] = { 4, 1, 9 };

    list_t la = list_create(arr);
    list_t lt = list_create(target);
    list_t lv = list_find(la, val);

    la = deleteNode(la, val);

    list_free(la);
    list_free(lt);
    free(lv);
}

START_TEST(test_official_2) {
    int arr[] = { 4, 5, 1, 9 }, val = 1;
    int target[] = { 4, 5, 9 };

    list_t la = list_create(arr);
    list_t lt = list_create(target);
    list_t lv = list_find(la, val);

    la = deleteNode(la, val);

    list_free(la);
    list_free(lt);
    free(lv);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}