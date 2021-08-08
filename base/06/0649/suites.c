/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/11 下午1:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0649.c"

START_TEST(test_official_1) {
    char *str = "RD";

    char *target = "Radiant", *ans = predictPartyVictory(str);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *str = "RDD";

    char *target = "Dire", *ans = predictPartyVictory(str);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_1) {
    char *str = "DDRRR";

    char *target = "Dire", *ans = predictPartyVictory(str);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_2) {
    char *str = "DRRD";

    char *target = "Dire", *ans = predictPartyVictory(str);

    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}