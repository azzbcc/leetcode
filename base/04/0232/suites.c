/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/5 上午12:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0232.c"

START_TEST(test_official) {
    MyQueue *queue = myQueueCreate();

    ck_assert_ptr_nonnull(queue);

    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    ck_assert_int_eq(1, myQueuePeek(queue));
    ck_assert_int_eq(1, myQueuePop(queue));
    ck_assert_int_eq(false, myQueueEmpty(queue));

    myQueueFree(queue);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}