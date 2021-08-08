/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/25 下午12:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0752.c"

START_TEST(test_official_1) {
    char *deadends[] = { "0201", "0101", "0102", "1212", "2002" }, *t = "0202";
    int target = 6, ans = openLock(deadends, LEN(deadends), t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *deadends[] = { "8888" }, *t = "0009";
    int target = 1, ans = openLock(deadends, LEN(deadends), t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *deadends[] = { "8887","8889","8878","8898","8788","8988","7888","9888" }, *t = "8888";
    int target = -1, ans = openLock(deadends, LEN(deadends), t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *deadends[] = { "0000" }, *t = "8888";
    int target = -1, ans = openLock(deadends, LEN(deadends), t);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}