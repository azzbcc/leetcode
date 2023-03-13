/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/13 上午11:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2383.c"

START_TEST(test_official_1) {
    int initialEnergy = 5, initialExperience = 3, target = 8;
    int energy[] = { 1, 4, 3, 2 }, experience[] = { 2, 6, 3, 1 };
    int ans = minNumberOfHours(initialEnergy, initialExperience, energy, LEN(energy), experience, LEN(experience));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int initialEnergy = 2, initialExperience = 4, target = 0;
    int energy[] = { 1 }, experience[] = { 3 };
    int ans = minNumberOfHours(initialEnergy, initialExperience, energy, LEN(energy), experience, LEN(experience));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}