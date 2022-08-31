/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/31 下午1:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0946.c"

START_TEST(test_official_1) {
    int pushed[] = { 1, 2, 3, 4, 5 }, popped[] = { 4, 5, 3, 2, 1 };
    bool target = true, ans = validateStackSequences(pushed, LEN(pushed), popped, LEN(popped));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int pushed[] = { 1, 2, 3, 4, 5 }, popped[] = { 4, 3, 5, 1, 2 };
    bool target = false, ans = validateStackSequences(pushed, LEN(pushed), popped, LEN(popped));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}