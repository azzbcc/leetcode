/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/9 下午3:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0497.c"

typedef struct {
    int x, y;
} point_t;
typedef struct {
    point_t p;
    int count;
    UT_hash_handle hh;
} * hash_t;
static void check(int **rects, size_t size) {
    hash_t hash = NULL, cur, next;
    int sum = 0, times = 10000;
    for (int i = 0; i < size; ++i) {
        sum += (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
    }

    Solution *solution = solutionCreate(rects, size, NULL);
    ck_assert_ptr_nonnull(solution);
    for (int i = 0; i < sum * times; ++i) {
        int len, *ans = solutionPick(solution, &len);
        ck_assert_int_eq(len, 2);
        HASH_FIND(hh, hash, ans, sizeof(point_t), cur);
        if (!cur) {
            cur = malloc(sizeof(*cur)), cur->p.x = ans[0], cur->p.y = ans[1], cur->count = 0;
            HASH_ADD(hh, hash, p, sizeof(point_t), cur);
        }
        cur->count += 1;
    }

    ck_assert_int_eq(HASH_COUNT(hash), sum);
    HASH_ITER(hh, hash, cur, next) {
        ck_assert_double_eq_tol(1. * cur->count / times, 1., 0.05);
        HASH_DEL(hash, cur);
        free(cur);
    }
    solutionFree(solution);
}

START_TEST(test_official) {
    int *rects[] = { (int[]) { -2, -2, 1, 1 }, (int[]) { 2, 2, 4, 6 } };
    check(rects, LEN(rects));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}