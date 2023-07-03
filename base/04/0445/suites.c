/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/3 15:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0445.c"

static list_t list_new(int n) {
    list_t head = NULL;
    for (list_t tmp; n || !head; head = tmp, n /= 10) {
        tmp      = malloc(sizeof(*tmp));
        tmp->val = n % 10, tmp->next = head;
    }
    return head;
}

START_TEST(test_official_1) {
    int a = 7243, b = 564;
    list_t l1 = list_new(a), l2 = list_new(b);
    list_t target = list_new(a + b), ans = addTwoNumbers(l1, l2);

    ck_assert(list_equal(ans, target));

    list_free(l1);
    list_free(l2);
    list_free(ans);
    list_free(target);
}

START_TEST(test_official_2) {
    int a = 243, b = 564;
    list_t l1 = list_new(a), l2 = list_new(b);
    list_t target = list_new(a + b), ans = addTwoNumbers(l1, l2);

    ck_assert(list_equal(ans, target));

    list_free(l1);
    list_free(l2);
    list_free(ans);
    list_free(target);
}

START_TEST(test_official_3) {
    int a = 0, b = 0;
    list_t l1 = list_new(a), l2 = list_new(b);
    list_t target = list_new(a + b), ans = addTwoNumbers(l1, l2);

    ck_assert(list_equal(ans, target));

    list_free(l1);
    list_free(l2);
    list_free(ans);
    list_free(target);
}

START_TEST(test_own) {
    int a = 9543, b = 564;
    list_t l1 = list_new(a), l2 = list_new(b);
    list_t target = list_new(a + b), ans = addTwoNumbers(l1, l2);

    ck_assert(list_equal(ans, target));

    list_free(l1);
    list_free(l2);
    list_free(ans);
    list_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}