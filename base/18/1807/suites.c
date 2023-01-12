/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/12 下午12:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1807.c"

START_TEST(test_official_1) {
    char *s = "(name)is(age)yearsold", **knowledge[] = { (char *[]) { "name", "bob" }, (char *[]) { "age", "two" } };
    char *target = "bobistwoyearsold", *ans = evaluate(s, knowledge, LEN(knowledge), NULL);
    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_official_2) {
    char *s = "hi(name)", **knowledge[] = { (char *[]) { "a", "b" } };
    char *target = "hi?", *ans = evaluate(s, knowledge, LEN(knowledge), NULL);
    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_official_3) {
    char *s = "(a)(a)(a)aaa", **knowledge[] = { (char *[]) { "a", "yes" } };
    char *target = "yesyesyesaaa", *ans = evaluate(s, knowledge, LEN(knowledge), NULL);
    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_own) {
    const int size = 100000, len = size / 3 * 10 + 1;
    char s[100000 + 1] = "a", **knowledge[] = { (char *[]) { "a", "aaaaaaaaaa" } };
    for (int i = 0; i < size / 3; sprintf(s + i * 3 + 1, "(a)"), ++i) {}
    char *ans = evaluate(s, knowledge, LEN(knowledge), NULL);
    ck_assert_int_eq(len, strlen(ans));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(ans[i], 'a');
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}