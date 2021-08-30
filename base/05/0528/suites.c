/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/30 上午10:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0528.c"

static void solutionCheck(Solution *solution, int arr[], size_t size) {
    int rate[size], sum = 0, times = 100000;

    for (int i = 0; i < size; ++i) {
        sum += arr[i], rate[i] = 0;
    }
    for (int i = 0; i < times; ++i) {
        rate[solutionPickIndex(solution)]++;
    }
    for (int i = 0; i < size; ++i) {
        ck_assert_double_eq_tol(1.0 * rate[i] / times, 1.0 * arr[i] / sum, 0.02);
    }
}

START_TEST(test_official_1) {
    int w[] = { 1 };

    Solution *solution = solutionCreate(w, LEN(w));
    ck_assert_ptr_nonnull(solution);

    solutionCheck(solution, w, LEN(w));

    solutionFree(solution);
}

START_TEST(test_official_2) {
    int w[] = { 1, 3 };

    Solution *solution = solutionCreate(w, LEN(w));
    ck_assert_ptr_nonnull(solution);

    solutionCheck(solution, w, LEN(w));

    solutionFree(solution);
}

START_TEST(test_own) {
    int w[] = { 1, 2, 3, 4 };

    Solution *solution = solutionCreate(w, LEN(w));
    ck_assert_ptr_nonnull(solution);

    solutionCheck(solution, w, LEN(w));

    solutionFree(solution);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}