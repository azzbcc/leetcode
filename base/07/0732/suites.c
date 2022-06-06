/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/6 下午12:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0732.c"

START_TEST(test_official) {
    int *arr[]   = { (int[]) { 10, 20 }, (int[]) { 50, 60 }, (int[]) { 10, 40 },
                     (int[]) { 5, 15 },  (int[]) { 5, 10 },  (int[]) { 25, 55 } };
    int target[] = { 1, 1, 2, 3, 3, 3 };

    MyCalendarThree *three = myCalendarThreeCreate();
    ck_assert_ptr_nonnull(three);
    for (int i = 0; i < LEN(arr); ++i) {
        ck_assert_int_eq(target[i], myCalendarThreeBook(three, arr[i][0], arr[i][1]));
    }
    myCalendarThreeFree(three);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}