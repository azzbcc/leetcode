/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/30 上午11:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0846.c"

START_TEST(test_official_1) {
    int hand[] = { 1, 2, 3, 6, 2, 3, 4, 7, 8 }, groupSize = 3;
    bool target = true, ans = isNStraightHand(hand, LEN(hand), groupSize);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int hand[] = { 1, 2, 3, 4, 5 }, groupSize = 4;
    bool target = false, ans = isNStraightHand(hand, LEN(hand), groupSize);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}