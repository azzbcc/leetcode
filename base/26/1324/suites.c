/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/19 下午5:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1324.c"

START_TEST(test_official_1) {
    int len;
    char *s        = "HOW ARE YOU";
    char *target[] = { "HAY", "ORO", "WEU" };
    char **ans     = printVertically(s, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *s        = "TO BE OR NOT TO BE";
    char *target[] = { "TBONTB", "OEROOE", "   T" };
    char **ans     = printVertically(s, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len;
    char *s        = "CONTEST IS COMING";
    char *target[] = { "CIC", "OSO", "N M", "T I", "E N", "S G", "T" };
    char **ans     = printVertically(s, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_own) {
    int len;
    char *s        = " ";
    char *target[] = {};
    char **ans     = printVertically(s, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}