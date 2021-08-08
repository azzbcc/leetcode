/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/23 上午11:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include "nested_integer.h"

#include "0341.c"
#include "nested_integer.c"

START_TEST(test_official_1) {
    char *s = "[[1,1],2,[1,1]]";
    int len, target[] = { 1, 1, 2, 1, 1 };
    nested_int_t *list = nested_create(s);

    struct NestedIterator *iter = nestedIterCreate(list->data, list->count);
    for (len = 0; nestedIterHasNext(iter); len++) {
        ck_assert_int_eq(target[len], nestedIterNext(iter));
    }
    ck_assert_int_eq(len, LEN(target));
    nestedIterFree(iter);

    nested_free(list);
}

START_TEST(test_official_2) {
    char *s = "[1,[4,[6]]]";
    int len, target[] = { 1, 4, 6 };
    nested_int_t *list = nested_create(s);

    struct NestedIterator *iter = nestedIterCreate(list->data, list->count);
    for (len = 0; nestedIterHasNext(iter); len++) {
        ck_assert_int_eq(target[len], nestedIterNext(iter));
    }
    ck_assert_int_eq(len, LEN(target));
    nestedIterFree(iter);

    nested_free(list);
}

START_TEST(test_failed_1) {
    char *s = "[[]]";
    int len, target[] = {};
    nested_int_t *list = nested_create(s);

    struct NestedIterator *iter = nestedIterCreate(list->data, list->count);
    for (len = 0; nestedIterHasNext(iter); len++) {
        ck_assert_int_eq(target[len], nestedIterNext(iter));
    }
    ck_assert_int_eq(len, LEN(target));
    nestedIterFree(iter);

    nested_free(list);
}

START_TEST(test_failed_2) {
#include "limit.c"
    int len;
    nested_int_t *list = nested_create(s);

    struct NestedIterator *iter = nestedIterCreate(list->data, list->count);
    for (len = 0; nestedIterHasNext(iter); len++) {
        ck_assert_int_eq(target[len], nestedIterNext(iter));
    }
    ck_assert_int_eq(len, LEN(target));
    nestedIterFree(iter);

    nested_free(list);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}