/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/28 09:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2558.c"

START_TEST(test_official_1) {
    int gifts[] = { 25, 64, 9, 4, 100 }, k = 4;
    long long target = 29, ans = pickGifts(gifts, LEN(gifts), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int gifts[] = { 1, 1, 1, 1 }, k = 4;
    long long target = 4, ans = pickGifts(gifts, LEN(gifts), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}