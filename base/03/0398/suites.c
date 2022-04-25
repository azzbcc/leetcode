/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/25 上午11:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0398.c"

void check(Solution *s, int key, int target[], size_t len) {
    int times = 1000000, rate[len];
    memset(rate, 0, sizeof(rate));
    for (int i = 0; i < times; ++i) {
        int t = solutionPick(s, key);
        for (int j = 0; j < len; ++j) {
            if (target[j] == t) rate[j]++;
        }
    }
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(1. * rate[i] / times, 1. / len, 0.002);
    }
}

START_TEST(test_official) {
    int nums[]         = { 1, 2, 3, 3, 3 };
    Solution *solution = solutionCreate(nums, LEN(nums));

    ck_assert_ptr_nonnull(solution);

    int target1[] = { 0 };
    check(solution, 1, target1, LEN(target1));

    int target2[] = { 1 };
    check(solution, 2, target2, LEN(target2));

    int target3[] = { 2, 3, 4 };
    check(solution, 3, target3, LEN(target3));

    solutionFree(solution);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}