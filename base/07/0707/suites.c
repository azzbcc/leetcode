/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/9/23 上午11:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0707.c"

START_TEST(test_official) {
    MyLinkedList *list = myLinkedListCreate();
    ck_assert_ptr_nonnull(list);

    myLinkedListAddAtHead(list, 1);
    myLinkedListAddAtTail(list, 3);
    myLinkedListAddAtIndex(list, 1, 2);
    ck_assert_int_eq(2, myLinkedListGet(list, 1));
    myLinkedListDeleteAtIndex(list, 1);
    ck_assert_int_eq(3, myLinkedListGet(list, 1));

    myLinkedListFree(list);
}

START_TEST(test_failed) {
    MyLinkedList *list = myLinkedListCreate();
    ck_assert_ptr_nonnull(list);

    myLinkedListAddAtIndex(list, 0, 10);
    myLinkedListAddAtIndex(list, 0, 20);
    myLinkedListAddAtIndex(list, 1, 30);
    ck_assert_int_eq(20, myLinkedListGet(list, 0));

    myLinkedListFree(list);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}