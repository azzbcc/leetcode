/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/7 16:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0344.c"

START_TEST(test_official_1) {
    char s[]      = { 'h', 'e', 'l', 'l', 'o' };
    char target[] = { 'o', 'l', 'l', 'e', 'h' };

    reverseString(s, LEN(s));
    ck_assert_mem_eq(s, target, sizeof(target));
}

START_TEST(test_official_2) {
    char s[]      = { 'H', 'a', 'n', 'n', 'a', 'h' };
    char target[] = { 'h', 'a', 'n', 'n', 'a', 'H' };

    reverseString(s, LEN(s));
    ck_assert_mem_eq(s, target, sizeof(target));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}