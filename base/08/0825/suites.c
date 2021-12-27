/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/27 上午11:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0825.c"

START_TEST(test_official_1) {
    int ages[] = { 16, 16 };
    int target = 2, ans = numFriendRequests(ages, LEN(ages));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int ages[] = { 16, 17, 18 };
    int target = 2, ans = numFriendRequests(ages, LEN(ages));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int ages[] = { 20, 30, 100, 110, 120 };
    int target = 3, ans = numFriendRequests(ages, LEN(ages));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}