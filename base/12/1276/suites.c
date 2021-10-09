/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/9 下午7:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1276.c"

START_TEST(test_official_1) {
    int len;
    int tomatoSlices = 16, cheeseSlices = 7;
    int target[] = { 1, 6 }, *ans = numOfBurgers(tomatoSlices, cheeseSlices, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    int tomatoSlices = 17, cheeseSlices = 4;
    int target[] = {}, *ans = numOfBurgers(tomatoSlices, cheeseSlices, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int len;
    int tomatoSlices = 4, cheeseSlices = 17;
    int target[] = {}, *ans = numOfBurgers(tomatoSlices, cheeseSlices, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_4) {
    int len;
    int tomatoSlices = 0, cheeseSlices = 0;
    int target[] = { 0, 0 }, *ans = numOfBurgers(tomatoSlices, cheeseSlices, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_5) {
    int len;
    int tomatoSlices = 2, cheeseSlices = 1;
    int target[] = { 0, 1 }, *ans = numOfBurgers(tomatoSlices, cheeseSlices, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}