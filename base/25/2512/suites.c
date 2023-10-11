/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/11 10:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2512.c"

START_TEST(test_official_1) {
    int id[] = { 1, 2 }, k = 2;
    char *positive[] = { "smart", "brilliant", "studious" }, *negative[] = { "not" },
         *report[] = { "this student is studious", "the student is smart" };
    int len, target[] = { 1, 2 };
    int *ans = topStudents(positive, LEN(positive), negative, LEN(negative), report, LEN(report), id, LEN(id), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int id[] = { 1, 2 }, k = 2;
    char *positive[] = { "smart", "brilliant", "studious" }, *negative[] = { "not" },
         *report[] = { "this student is not studious", "the student is smart" };
    int len, target[] = { 2, 1 };
    int *ans = topStudents(positive, LEN(positive), negative, LEN(negative), report, LEN(report), id, LEN(id), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int id[] = { 96537918, 589204657, 765963609, 613766496, 43871615, 189209587, 239084671, 908938263 }, k = 3;
    char *positive[] = { "fkeofjpc", "qq", "iio" },
         *negative[] = { "jdh", "khj", "eget", "rjstbhe", "yzyoatfyx", "wlinrrgcm" },
         *report[]   = { "rjstbhe eget kctxcoub urrmkhlmi yniqafy fkeofjpc iio yzyoatfyx khj iio",
                         "gpnhgabl qq qq fkeofjpc dflidshdb qq iio khj qq yzyoatfyx",
                         "tizpzhlbyb eget z rjstbhe iio jdh jdh iptxh qq rjstbhe",
                         "jtlghe wlinrrgcm jnkdbd k iio et rjstbhe iio qq jdh",
                         "yp fkeofjpc lkhypcebox rjstbhe ewwykishv egzhne jdh y qq qq",
                         "fu ql iio fkeofjpc jdh luspuy yzyoatfyx li qq v",
                         "wlinrrgcm iio qq omnc sgkt tzgev iio iio qq qq",
                         "d vhg qlj khj wlinrrgcm qq f jp zsmhkjokmb rjstbhe" };
    int len, target[] = { 239084671, 589204657, 43871615 };
    int *ans = topStudents(positive, LEN(positive), negative, LEN(negative), report, LEN(report), id, LEN(id), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}