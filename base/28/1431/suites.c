/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/30 下午2:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1431.c"

START_TEST(test_official_1) {
    int candies[] = { 2, 3, 5, 1, 3 }, extraCandies = 3, len;
    bool target[] = { true, true, true, false, true };
    bool *ans     = kidsWithCandies(candies, LEN(candies), extraCandies, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int candies[] = { 4, 2, 1, 1, 2 }, extraCandies = 1, len;
    bool target[] = { true, false, false, false, false };
    bool *ans     = kidsWithCandies(candies, LEN(candies), extraCandies, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int candies[] = { 12, 1, 12 }, extraCandies = 10, len;
    bool target[] = { true, false, true };
    bool *ans     = kidsWithCandies(candies, LEN(candies), extraCandies, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(ans[i], target[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}
