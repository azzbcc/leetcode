/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/24 下午2:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0638.c"

START_TEST(test_official_1) {
    int price[] = { 2, 5 }, *special[] = { (int[]) { 3, 0, 5 }, (int[]) { 1, 2, 10 } }, needs[] = { 3, 2 };
    int target = 14, ans = shoppingOffers(price, LEN(price), special, LEN(special), NULL, needs, LEN(needs));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int price[] = { 2, 3, 4 }, *special[] = { (int[]) { 1, 1, 0, 4 }, (int[]) { 2, 2, 1, 9 } }, needs[] = { 1, 2, 1 };
    int target = 11, ans = shoppingOffers(price, LEN(price), special, LEN(special), NULL, needs, LEN(needs));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}