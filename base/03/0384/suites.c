/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/22 上午11:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0384.c"

void solution_reset_check(Solution *s, int arr[], size_t size) {
    int len, *ans = solutionReset(s, &len);

    ck_assert_int_eq(len, size);
    ck_assert_mem_eq(ans, arr, size * sizeof(int));
}
static const int FAC[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
int cantor(int a[], size_t size) {
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        int smaller = 0;
        for (int j = i + 1; j < size; ++j) {
            if (a[j] < a[i]) smaller++;
        }
        ans += FAC[size - i - 1] * smaller;
    }
    return ans;
}
void solution_shuffle_check(Solution *s, size_t size) {
    int rate[FAC[size]], times = 10000, len;

    solutionShuffle(s, &len);
    ck_assert_int_eq(len, size);

    memset(rate, 0, sizeof(rate));
    for (int i = 0; i < FAC[size] * times; ++i) {
        int *target = solutionShuffle(s, &len);
        rate[cantor(target, len)]++;
    }
    for (int i = 0; i < LEN(rate); ++i) {
        ck_assert_double_eq_tol(1. * rate[i] / times, 1., 0.05);
    }
}

START_TEST(test_official) {
    int arr[]          = { 1, 2, 3 };
    Solution *solution = solutionCreate(arr, LEN(arr));
    ck_assert_ptr_nonnull(solution);

    solution_shuffle_check(solution, LEN(arr));
    solution_reset_check(solution, arr, LEN(arr));

    solutionFree(solution);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}