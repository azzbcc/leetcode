/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/21 下午8:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "offer_59_II.c"

START_TEST(test_official_1) {
    MaxQueue *queue = maxQueueCreate();
    ck_assert_ptr_nonnull(queue);

    maxQueuePush_back(queue, 1);
    maxQueuePush_back(queue, 2);
    ck_assert_int_eq(2, maxQueueMax_value(queue));
    ck_assert_int_eq(1, maxQueuePop_front(queue));
    ck_assert_int_eq(2, maxQueueMax_value(queue));

    maxQueueFree(queue);
}

START_TEST(test_official_2) {
    MaxQueue *queue = maxQueueCreate();
    ck_assert_ptr_nonnull(queue);

    ck_assert_int_eq(-1, maxQueuePop_front(queue));
    ck_assert_int_eq(-1, maxQueueMax_value(queue));

    maxQueueFree(queue);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}