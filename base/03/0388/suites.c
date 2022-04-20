/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/20 下午3:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0388.c"

START_TEST(test_official_1) {
    char *input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    int target = 20, ans = lengthLongestPath(input);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    int target = 32, ans = lengthLongestPath(input);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *input = "a";
    int target = 0, ans = lengthLongestPath(input);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *input = "file1.txt\nfile2.txt\nlongfile.txt";
    int target = 12, ans = lengthLongestPath(input);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}