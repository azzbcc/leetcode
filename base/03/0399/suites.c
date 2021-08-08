/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/6 下午2:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0399.c"

START_TEST(test_official_1) {
    int len;

    double values[] = { 2.0, 3.0 };
    double target[] = { 6.00000, 0.50000, -1.00000, 1.00000, -1.00000 };

    char *equations[][2]   = { { "a", "b" }, { "b", "c" } };
    char **gridEquations[] = { equations[0], equations[1] };

    char *queries[][2]   = { { "a", "c" }, { "b", "a" }, { "a", "e" }, { "a", "a" }, { "x", "x" } };
    char **gridQueries[] = { queries[0], queries[1], queries[2], queries[3], queries[4] };

    double *ans = calcEquation(gridEquations, LEN(gridEquations), NULL, values, LEN(values), gridQueries,
                               LEN(gridQueries), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.001);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;

    double values[] = { 1.5, 2.5, 5.0 };
    double target[] = { 3.75000, 0.40000, 5.00000, 0.20000 };

    char *equations[][2]   = { { "a", "b" }, { "b", "c" }, { "bc", "cd" } };
    char **gridEquations[] = { equations[0], equations[1], equations[2] };

    char *queries[][2]   = { { "a", "c" }, { "c", "b" }, { "bc", "cd" }, { "cd", "bc" } };
    char **gridQueries[] = { queries[0], queries[1], queries[2], queries[3] };

    double *ans = calcEquation(gridEquations, LEN(gridEquations), NULL, values, LEN(values), gridQueries,
                               LEN(gridQueries), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.001);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len;

    double values[] = { 0.5 };
    double target[] = { 0.50000, 2.00000, -1.00000, -1.00000 };

    char *equations[][2]   = { { "a", "b" } };
    char **gridEquations[] = { equations[0] };

    char *queries[][2]   = { { "a", "b" }, { "b", "a" }, { "a", "c" }, { "x", "y" } };
    char **gridQueries[] = { queries[0], queries[1], queries[2], queries[3] };

    double *ans = calcEquation(gridEquations, LEN(gridEquations), NULL, values, LEN(values), gridQueries,
                               LEN(gridQueries), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.001);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len;

    double values[] = { 2.0, 3.0, 0.5, 5.0 };
    double target[] = { 0.06667 };

    char *equations[][2]   = { { "a", "c" }, { "b", "e" }, { "c", "d" }, { "e", "d" } };
    char **gridEquations[] = { equations[0], equations[1], equations[2], equations[3] };

    char *queries[][2]   = { { "a", "b" } };
    char **gridQueries[] = { queries[0] };

    double *ans = calcEquation(gridEquations, LEN(gridEquations), NULL, values, LEN(values), gridQueries,
                               LEN(gridQueries), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.001);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}