/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/8 下午9:57
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1125.c"

START_TEST(test_official_1) {
    char *skills[]  = { "java", "nodejs", "reactjs" };
    char **people[] = { (char *[]) { "java" }, (char *[]) { "nodejs" }, (char *[]) { "nodejs", "reactjs" } };
    int len, col[] = { 1, 1, 2 }, target[] = { 0, 2 };
    int *ans = smallestSufficientTeam(skills, LEN(skills), people, LEN(people), col, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    char *skills[]  = { "algorithms", "math", "java", "reactjs", "csharp", "aws" };
    char **people[] = { (char *[]) { "algorithms", "math", "java" },
                        (char *[]) { "algorithms", "math", "reactjs" },
                        (char *[]) { "java", "csharp", "aws" },
                        (char *[]) { "reactjs", "csharp" },
                        (char *[]) { "csharp", "math" },
                        (char *[]) { "aws", "java" } };
    int len, col[] = { 3, 3, 3, 2, 2, 2 }, target[] = { 1, 2 };
    int *ans = smallestSufficientTeam(skills, LEN(skills), people, LEN(people), col, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_overflow) {
    char *skills[]  = { "mwobudvo", "goczubcwnfze", "yspbsez", "pf", "ey", "hkq" };
    char **people[] = { (char *[]) {},
                        (char *[]) { "mwobudvo" },
                        (char *[]) { "hkq" },
                        (char *[]) { "pf" },
                        (char *[]) { "pf" },
                        (char *[]) { "mwobudvo", "pf" },
                        (char *[]) {},
                        (char *[]) { "yspbsez" },
                        (char *[]) {},
                        (char *[]) { "hkq" },
                        (char *[]) {},
                        (char *[]) {},
                        (char *[]) { "goczubcwnfze", "pf", "hkq" },
                        (char *[]) { "goczubcwnfze" },
                        (char *[]) { "hkq" },
                        (char *[]) { "mwobudvo" },
                        (char *[]) {},
                        (char *[]) { "mwobudvo", "pf" },
                        (char *[]) { "pf", "ey" },
                        (char *[]) { "mwobudvo" },
                        (char *[]) { "hkq" },
                        (char *[]) {},
                        (char *[]) { "pf" },
                        (char *[]) { "mwobudvo", "yspbsez" },
                        (char *[]) { "mwobudvo", "goczubcwnfze" },
                        (char *[]) { "goczubcwnfze", "pf" },
                        (char *[]) { "goczubcwnfze" },
                        (char *[]) { "goczubcwnfze" },
                        (char *[]) { "mwobudvo" },
                        (char *[]) { "mwobudvo", "goczubcwnfze" },
                        (char *[]) {},
                        (char *[]) { "goczubcwnfze" },
                        (char *[]) {},
                        (char *[]) { "goczubcwnfze" },
                        (char *[]) { "mwobudvo" },
                        (char *[]) {},
                        (char *[]) { "hkq" },
                        (char *[]) { "yspbsez" },
                        (char *[]) { "mwobudvo" },
                        (char *[]) { "goczubcwnfze", "ey" } };
    int len, target[] = { 12, 18, 23 };
    int col[] = { 0, 1, 1, 1, 1, 2, 0, 1, 0, 1, 0, 0, 3, 1, 1, 1, 0, 2, 2, 1,
                  1, 0, 1, 2, 2, 2, 1, 1, 1, 2, 0, 1, 0, 1, 1, 0, 1, 1, 1, 2 };
    int *ans  = smallestSufficientTeam(skills, LEN(skills), people, LEN(people), col, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_overflow);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}