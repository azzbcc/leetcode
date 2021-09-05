/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/5 下午12:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

static int rand7();

#include "0470.c"

static int rand7() {
    return rand() % 7 + 1;
}
static void check_rand10() {
    int times = 1000000;
    int rate[11] = {0};
    for (int i = 0; i < times; ++i) {
        rate[rand10()]++;
    }
    for (int i = 1; i < LEN(rate); ++i) {
        ck_assert_double_eq_tol(1.0 * rate[i] / times, 0.1, 0.002);
    }
}

START_TEST(test_official) {
    check_rand10();
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}