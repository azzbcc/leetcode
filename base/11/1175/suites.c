/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/30 下午5:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1175.c"

START_TEST(test_official_1) {
    int target = 12, ans = numPrimeArrangements(5);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int target = 682289015, ans = numPrimeArrangements(100);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}