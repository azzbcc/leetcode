/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/17 下午12:28
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0115.c"

START_TEST(test_official_1) {
    char *s = "rabbbit", *t = "rabbit";
    int target = 3, ans = numDistinct(s, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "babgbag", *t = "bag";
    int target = 5, ans = numDistinct(s, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own_1) {
    char *s = "ababababa", *t = "aa";
    int target = 10, ans = numDistinct(s, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own_2) {
    char s[41] = { 0 }, t[11] = { 0 };
    for (int i = 0; i < LEN(s) - 1; s[i++] = 'a') {}
    for (int i = 0; i < LEN(t) - 1; t[i++] = 'a') {}
    int target = 847660528, ans = numDistinct(s, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
    char *t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    char *s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtg"
              "lewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdj"
              "hcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndin"
              "adtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurex"
              "dtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspey"
              "nlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakd"
              "igjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclid"
              "zybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoai"
              "omgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaie"
              "hlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    int target = 543744000, ans = numDistinct(s, t);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_own_1);
    tcase_add_test(t, test_own_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}