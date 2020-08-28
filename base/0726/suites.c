/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/28 下午1:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0726.c"

START_TEST(test_official_1) {
    char *input  = "H2O";
    char *target = "H2O", *ans = countOfAtoms(input);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_2) {
    char *input  = "Mg(OH)2";
    char *target = "H2MgO2", *ans = countOfAtoms(input);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_3) {
    char *input  = "K4(ON(SO3)2)2";
    char *target = "K4N2O14S4", *ans = countOfAtoms(input);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_failed) {
    char *input  = "((N42)24(OB40Li30CHe3O48LiNN26)33(C12Li48N30H13HBe31)21(BHN30Li26BCBe47N40)15(H5)16)14";
    char *target = "B18900Be18984C4200H5446He1386Li33894N50106O22638", *ans = countOfAtoms(input);

    ck_assert_str_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}