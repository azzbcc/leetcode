/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/13 上午10:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0412.c"

START_TEST(test_offical) {
    int len, n = 15;
    char *target[] = { "1",    "2",    "Fizz", "4",    "Buzz", "Fizz", "7",       "8",
                       "Fizz", "Buzz", "11",   "Fizz", "13",   "14",   "FizzBuzz" };
    char **ans     = fizzBuzz(n, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_offical);
}