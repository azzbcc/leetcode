/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/26 下午2:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1342.c"

START_TEST(test_official_1) {
    int target = 6, ans = numberOfSteps(14);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int target = 4, ans = numberOfSteps(8);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int target = 12, ans = numberOfSteps(123);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}