/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/7 下午5:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0433.c"

START_TEST(test_official_1) {
    char *start = "AACCGGTT", *end = "AACCGGTA", *bank[] = { "AACCGGTA" };
    int target = 1, ans = minMutation(start, end, bank, LEN(bank));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *start = "AACCGGTT", *end = "AAACGGTA", *bank[] = { "AACCGGTA", "AACCGCTA", "AAACGGTA" };
    int target = 2, ans = minMutation(start, end, bank, LEN(bank));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *start = "AAAAACCC", *end = "AACCCCCC", *bank[] = { "AAAACCCC", "AAACCCCC", "AACCCCCC" };
    int target = 3, ans = minMutation(start, end, bank, LEN(bank));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    char *start = "AACCGGTT", *end = "AACCGGTA", *bank[] = {};
    int target = -1, ans = minMutation(start, end, bank, LEN(bank));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    char *start = "AACCGGTT", *end = "AAACGGTA", *bank[] = { "AACCGATT", "AACCGATA", "AAACGATA", "AAACGGTA" };
    int target = 4, ans = minMutation(start, end, bank, LEN(bank));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}