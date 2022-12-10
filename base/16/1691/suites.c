/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/10 下午6:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1691.c"

START_TEST(test_official_1) {
    int *cuboids[] = { (int[]) { 50, 45, 20 }, (int[]) { 95, 37, 53 }, (int[]) { 45, 23, 12 } };
    int target = 190, ans = maxHeight(cuboids, LEN(cuboids), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *cuboids[] = { (int[]) { 38, 25, 45 }, (int[]) { 76, 35, 3 } };
    int target = 76, ans = maxHeight(cuboids, LEN(cuboids), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *cuboids[] = { (int[]) { 7, 11, 17 }, (int[]) { 7, 17, 11 }, (int[]) { 11, 7, 17 },
                       (int[]) { 11, 17, 7 }, (int[]) { 17, 7, 11 }, (int[]) { 17, 11, 7 } };
    int target = 102, ans = maxHeight(cuboids, LEN(cuboids), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int *cuboids[] = { (int[]) { 92, 47, 83 }, (int[]) { 75, 20, 87 }, (int[]) { 68, 12, 83 }, (int[]) { 12, 85, 15 },
                       (int[]) { 16, 24, 47 }, (int[]) { 69, 65, 35 }, (int[]) { 96, 56, 93 }, (int[]) { 89, 93, 11 },
                       (int[]) { 86, 20, 41 }, (int[]) { 69, 77, 12 }, (int[]) { 83, 80, 97 }, (int[]) { 90, 22, 36 } };
    int target = 447, ans = maxHeight(cuboids, LEN(cuboids), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}