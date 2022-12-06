/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/6 下午1:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1805.c"

START_TEST(test_official_1) {
    char *word = "a123bc34d8ef34";
    int target = 3, ans = numDifferentIntegers(word);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *word = "leet1234code234";
    int target = 2, ans = numDifferentIntegers(word);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *word = "a1b01c001";
    int target = 1, ans = numDifferentIntegers(word);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *word = "a0b00c000d";
    int target = 1, ans = numDifferentIntegers(word);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow) {
    char *word = "56842596268670798706090381118606668646529213195339344710735011864206145800607487683133529966532511956"
                 "65479045547685197839110538180348415159045039154685797427102044628308561124271593797726026400668479138"
                 "75895252250031527093379470448444505326019389870829064237072499883672716998162471648589871105233122821"
                 "91935595043559525311612349266869405092561339186784953014600700596927545616800964077367051621515472858"
                 "61234377097580578296959558654434608827650928973007887285618347478907986105760180324984020484110639655"
                 "02309436847717782347700398303415519355496353238152804338609901591031335149273607627292707160644626409"
                 "90561612069433136634819749816481507256843994892804057650196405825565897743722681302907723152051050955"
                 "44517857762728255610939635798897528246117477931391747845300229080963678197909717746214812469623699528"
                 "18210437849931023931966847600707390092715157583569604039349719688910050717340105013955300596239294750"
                 "1866983945172050997143872813027028092734354451524303601940765090648547079444365761751927376";
    int target = 1, ans = numDifferentIntegers(word);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *word = "1904440555a1";
    int target = 2, ans = numDifferentIntegers(word);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_overflow);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}