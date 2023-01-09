/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/9 下午2:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1806.c"

START_TEST(test_official_1) {
    int n      = 2;
    int target = 1, ans = reinitializePermutation(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 4;
    int target = 2, ans = reinitializePermutation(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n      = 6;
    int target = 4, ans = reinitializePermutation(n);
    ck_assert_int_eq(ans, target);
}

static int count_permutation(int n) {
    int arr[n], old[n], count = 1;
    for (int i = 0; i < n; arr[i] = i, ++i) {}
    memcpy(old, arr, sizeof(arr));
    for (int new[n];; ++count) {
        for (int i = 0; i < n; ++i) {
            new[i] = old[i % 2 ? (n / 2 + (i - 1) / 2) : (i / 2)];
        }
        if (!memcmp(new, arr, sizeof(arr))) break;
        memcpy(old, new, sizeof(new));
    }
    return count;
}
START_TEST(test_own) {
    for (int n = 2; n <= 1000; n += 2) {
        int target = count_permutation(n);
        int ans    = reinitializePermutation(n);
        ck_assert_int_eq(ans, target);
    }
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}