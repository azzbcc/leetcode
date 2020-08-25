/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/25 下午7:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "03_04.c"

START_TEST(test_official) {
    MyQueue *q =  myQueueCreate();

    ck_assert_int_eq(true, myQueueEmpty(q));

    myQueuePush(q, 1);
    ck_assert_int_eq(false, myQueueEmpty(q));

    myQueuePush(q, 2);

    ck_assert_int_eq(1, myQueuePeek(q));
    ck_assert_int_eq(1, myQueuePop(q));
    ck_assert_int_eq(false, myQueueEmpty(q));

    myQueueFree(q);
}


void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}