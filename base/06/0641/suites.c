/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/15 下午7:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0641.c"

START_TEST(test_official) {
    MyCircularDeque *deque = myCircularDequeCreate(3);
    ck_assert_ptr_nonnull(deque);

    ck_assert_int_eq(true, myCircularDequeInsertLast(deque, 1));
    ck_assert_int_eq(true, myCircularDequeInsertLast(deque, 2));
    ck_assert_int_eq(true, myCircularDequeInsertFront(deque, 3));
    ck_assert_int_eq(false, myCircularDequeInsertFront(deque, 4));
    ck_assert_int_eq(2, myCircularDequeGetRear(deque));
    ck_assert_int_eq(true, myCircularDequeIsFull(deque));
    ck_assert_int_eq(true, myCircularDequeDeleteLast(deque));
    ck_assert_int_eq(true, myCircularDequeInsertFront(deque, 4));
    ck_assert_int_eq(4, myCircularDequeGetFront(deque));

    myCircularDequeFree(deque);
}

START_TEST(test_failed) {
    MyCircularDeque *deque = myCircularDequeCreate(5);
    ck_assert_ptr_nonnull(deque);

    ck_assert_int_eq(true, myCircularDequeInsertFront(deque, 7));
    ck_assert_int_eq(true, myCircularDequeInsertLast(deque, 0));
    ck_assert_int_eq(7, myCircularDequeGetFront(deque));
    ck_assert_int_eq(true, myCircularDequeInsertLast(deque, 3));
    ck_assert_int_eq(7, myCircularDequeGetFront(deque));
    ck_assert_int_eq(true, myCircularDequeInsertFront(deque, 9));
    ck_assert_int_eq(3, myCircularDequeGetRear(deque));
    ck_assert_int_eq(9, myCircularDequeGetFront(deque));
    ck_assert_int_eq(9, myCircularDequeGetFront(deque));
    ck_assert_int_eq(true, myCircularDequeDeleteLast(deque));
    ck_assert_int_eq(0, myCircularDequeGetRear(deque));

    myCircularDequeFree(deque);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}