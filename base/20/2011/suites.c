/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/23 上午11:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2011.c"

START_TEST(test_official_1) {
    char *operations[] = { "--X", "X++", "X++" };
    int target = 1, ans = finalValueAfterOperations(operations, LEN(operations));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *operations[] = { "++X", "++X", "X++" };
    int target = 3, ans = finalValueAfterOperations(operations, LEN(operations));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *operations[] = { "X++", "++X", "--X", "X--" };
    int target = 0, ans = finalValueAfterOperations(operations, LEN(operations));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}