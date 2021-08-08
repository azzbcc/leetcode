/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/22 下午1:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0191.c"

START_TEST(test_official_1) {
    uint32_t n = 0b00000000000000000000000000001011;
    ck_assert_int_eq(3, hammingWeight(n));
}

START_TEST(test_official_2) {
    uint32_t n = 0b00000000000000000000000010000000;
    ck_assert_int_eq(1, hammingWeight(n));
}

START_TEST(test_official_3) {
    uint32_t n = 0b11111111111111111111111111111101;
    ck_assert_int_eq(31, hammingWeight(n));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}