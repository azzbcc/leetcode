/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/4 上午11:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */

#include <common.h>
#include <list.h>

#include "0160.c"

START_TEST(test_official_1) {
    int listA[] = { 4, 1, 8, 4, 5 }, listB[] = { 5, 0, 1, 8, 4, 5 }, skipA = 2, skipB = 3;
    list_t la = list_create(listA), lb = list_create_size(listB, skipB), target = la, tail = lb;
    for (int i = 0; i < skipA; ++i, target = target->next) {}
    for (int i = 1; i < skipB; ++i, tail = tail->next) {}

    tail->next = target;
    list_t ans = getIntersectionNode(la, lb);
    ck_assert_ptr_eq(ans, target);
    tail->next = NULL;

    list_free(la), list_free(lb);
}

START_TEST(test_official_2) {
    int listA[] = { 0, 9, 1, 2, 4 }, listB[] = { 3, 2, 4 }, skipA = 3, skipB = 1;
    list_t la = list_create(listA), lb = list_create_size(listB, skipB), target = la, tail = lb;
    for (int i = 0; i < skipA; ++i, target = target->next) {}
    for (int i = 1; i < skipB; ++i, tail = tail->next) {}

    tail->next = target;
    list_t ans = getIntersectionNode(la, lb);
    ck_assert_ptr_eq(ans, target);
    tail->next = NULL;

    list_free(la), list_free(lb);
}

START_TEST(test_official_3) {
    int listA[] = { 2, 6, 4 }, listB[] = { 1, 5 }, skipA = 3, skipB = 2;
    list_t la = list_create(listA), lb = list_create_size(listB, skipB), target = la, tail = lb;
    for (int i = 0; i < skipA; ++i, target = target->next) {}
    for (int i = 1; i < skipB; ++i, tail = tail->next) {}

    tail->next = target;
    list_t ans = getIntersectionNode(la, lb);
    ck_assert_ptr_eq(ans, target);
    tail->next = NULL;

    list_free(la), list_free(lb);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}