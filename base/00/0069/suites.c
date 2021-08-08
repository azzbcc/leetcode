/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/3 下午2:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0069.c"

START_TEST(test_official_1) {
    int target = 2, ans = mySqrt(4);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_2) {
    int target = 2, ans = mySqrt(8);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_own) {
    ck_assert_int_eq(0, mySqrt(0));
    ck_assert_int_eq(1, mySqrt(1));
    ck_assert_int_eq(1732, mySqrt(3000000));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}