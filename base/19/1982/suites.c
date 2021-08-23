/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/23 下午5:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1982.c"

static int array_comp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
static int *sumTarget(int arr[], size_t size, int *resLen) {
    int *ans = malloc((*resLen = 1 << size) * sizeof(int));
    for (int mask = 0; mask < 1 << size; ++mask) {
        ans[mask] = 0;
        for (int i = 0; i < size; ++i) {
            if (mask & 1 << i) ans[mask] += arr[i];
        }
    }
    return ans;
}

START_TEST(test_official_1) {
    int n = 3, sums[] = { -3, -2, -1, 0, 0, 1, 2, 3 };

    int copy[LEN(sums)];
    memcpy(copy, sums, sizeof(sums));
    int len, *ans = recoverArray(n, copy, LEN(sums), &len);
    ck_assert_int_eq(len, n);

    int *target = sumTarget(ans, len, &len);
    ck_assert_int_eq(len, LEN(sums));

    qsort(sums, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);

    ck_assert_mem_eq(target, sums, sizeof(sums));

    free(ans);
    free(target);
}

START_TEST(test_official_2) {
    int n = 2, sums[] = { 0, 0, 0, 0 };

    int copy[LEN(sums)];
    memcpy(copy, sums, sizeof(sums));
    int len, *ans = recoverArray(n, copy, LEN(sums), &len);
    ck_assert_int_eq(len, n);

    int *target = sumTarget(ans, len, &len);
    ck_assert_int_eq(len, LEN(sums));

    qsort(sums, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);
    ck_assert_mem_eq(target, sums, sizeof(sums));

    free(ans);
    free(target);
}

START_TEST(test_official_3) {
    int n = 4, sums[] = { 0, 0, 5, 5, 4, -1, 4, 9, 9, -1, 4, 3, 4, 8, 3, 8 };
    int copy[LEN(sums)];
    memcpy(copy, sums, sizeof(sums));
    int len, *ans = recoverArray(n, copy, LEN(sums), &len);
    ck_assert_int_eq(len, n);

    int *target = sumTarget(ans, len, &len);
    ck_assert_int_eq(len, LEN(sums));

    qsort(sums, len, sizeof(int), array_comp);
    qsort(target, len, sizeof(int), array_comp);
    ck_assert_mem_eq(target, sums, sizeof(sums));

    free(ans);
    free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}