/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/27 下午12:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0519.c"

void solution_rand_check(Solution *s, int m, int n) {
    int rate[m][n];

    memset(rate, 0, sizeof(rate));
    for (int i = 0; i < m * n; ++i) {
        int len, *ans = solutionFlip(s, &len);
        ck_assert_int_eq(len, 2);
        rate[ans[0]][ans[1]]++;
        free(ans);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ck_assert_int_eq(rate[i][j], 1);
        }
    }
}
START_TEST(test_official) {
    int m = 3, n = 1;
    Solution *s = solutionCreate(m, n);
    ck_assert_ptr_nonnull(s);

    solution_rand_check(s, m, n);
    solutionReset(s);
    solution_rand_check(s, m, n);

    solutionFree(s);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}