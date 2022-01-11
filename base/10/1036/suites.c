/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/11 下午1:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1036.c"

START_TEST(test_official_1) {
    int *blocked[] = { (int[]) { 0, 1 }, (int[]) { 1, 0 } };
    int from[] = { 0, 0 }, to[] = { 0, 2 };
    bool target = false, ans = isEscapePossible(blocked, LEN(blocked), NULL, from, LEN(from), to, LEN(to));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *blocked[] = {};
    int from[] = { 0, 0 }, to[] = { 999999, 999999 };
    bool target = true, ans = isEscapePossible(blocked, LEN(blocked), NULL, from, LEN(from), to, LEN(to));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int *blocked[] = { (int[]) { 691938, 300406 }, (int[]) { 710196, 624190 }, (int[]) { 858790, 609485 },
                       (int[]) { 268029, 225806 }, (int[]) { 200010, 188664 }, (int[]) { 132599, 612099 },
                       (int[]) { 329444, 633495 }, (int[]) { 196657, 757958 }, (int[]) { 628509, 883388 } };
    int from[] = { 655988, 180910 }, to[] = { 267728, 840949 };
    bool target = true, ans = isEscapePossible(blocked, LEN(blocked), NULL, from, LEN(from), to, LEN(to));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
#include "tle.c"
    int from[] = { 362662, 757270 }, to[] = { 879297, 485661 };
    bool target = true, ans = isEscapePossible(blocked, LEN(blocked), NULL, from, LEN(from), to, LEN(to));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}