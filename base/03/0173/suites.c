/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/15 下午1:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0173.c"

START_TEST(test_official) {
    int arr[] = { 7, 3, 15, null, null, 9, 20 };
    tree_t t  = tree_create(arr);

    BSTIterator *iter = bSTIteratorCreate(t);
    ck_assert_int_eq(3, bSTIteratorNext(iter));
    ck_assert_int_eq(7, bSTIteratorNext(iter));
    ck_assert_int_eq(true, bSTIteratorHasNext(iter));
    ck_assert_int_eq(9, bSTIteratorNext(iter));
    ck_assert_int_eq(true, bSTIteratorHasNext(iter));
    ck_assert_int_eq(15, bSTIteratorNext(iter));
    ck_assert_int_eq(true, bSTIteratorHasNext(iter));
    ck_assert_int_eq(20, bSTIteratorNext(iter));
    ck_assert_int_eq(false, bSTIteratorHasNext(iter));
    bSTIteratorFree(iter);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}
