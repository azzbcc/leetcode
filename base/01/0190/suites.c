/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/29 下午1:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0190.c"

START_TEST(test_official_1) {
    uint32_t n   = 0b00000010100101000001111010011100;
    uint32_t t   = 0b00111001011110000010100101000000;
    uint32_t ans = reverseBits(n);

    ck_assert_int_eq(ans, t);
}

START_TEST(test_official_2) {
    uint32_t n   = 0b11111111111111111111111111111101;
    uint32_t t   = 0b10111111111111111111111111111111;
    uint32_t ans = reverseBits(n);

    ck_assert_int_eq(ans, t);
}

START_TEST(test_official_3) {
    uint32_t n   = 0b00000010100101000001111010011100;
    uint32_t t   = 0b00111001011110000010100101000000;
    uint32_t ans = reverseBits(n);

    ck_assert_int_eq(ans, t);
}

START_TEST(test_official_4) {
    uint32_t n   = 0b11111111111111111111111111111101;
    uint32_t t   = 0b10111111111111111111111111111111;
    uint32_t ans = reverseBits(n);

    ck_assert_int_eq(ans, t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}