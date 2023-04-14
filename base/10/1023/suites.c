/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/14 上午10:42
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1023.c"

START_TEST(test_official_1) {
    int len;
    char *queries[] = { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" };
    char *pattern   = "FB";
    bool target[]   = { true, false, true, true, false };
    bool *ans       = camelMatch(queries, LEN(queries), pattern, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *queries[] = { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" };
    char *pattern   = "FoBa";
    bool target[]   = { true, false, true, false, false };
    bool *ans       = camelMatch(queries, LEN(queries), pattern, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int len;
    char *queries[] = { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" };
    char *pattern   = "FoBaT";
    bool target[]   = { false, true, false, false, false };
    bool *ans       = camelMatch(queries, LEN(queries), pattern, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}