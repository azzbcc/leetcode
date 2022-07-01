/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/7/1 下午7:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0241.c"

int comp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}

START_TEST(test_official_1) {
    char *expression = "2-1-1";
    int target[]     = { 0, 2 };
    int len, *ans = diffWaysToCompute(expression, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(ans[0]), comp);
    qsort(target, len, sizeof(target[0]), comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    char *expression = "2*3-4*5";
    int target[]     = { -34, -14, -10, -10, 10 };
    int len, *ans = diffWaysToCompute(expression, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(ans[0]), comp);
    qsort(target, len, sizeof(target[0]), comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_limit) {
    char *expression = "1+1+1+1+1+11+1+1+1+1";
    int len, *ans = diffWaysToCompute(expression, &len);

    ck_assert_int_eq(len, 4862);
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(ans[i], 20);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}