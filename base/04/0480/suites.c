/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/3 下午17:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0480.c"

START_TEST(test_official) {
    double target[] = { 1, -1, -1, 3, 5, 6 };
    int len, arr[] = { 1, 3, -1, -3, 5, 3, 6, 7 }, k = 3;
    double *ans = medianSlidingWindow(arr, LEN(arr), k, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.00001);
    }
    free(ans);
}

START_TEST(test_overflow) {
    double target[] = { 1073741824.00000, 1.50000, 2.50000, 3.50000, 4.50000, 5.50000, 6.50000, 1073741827.00000 };
    int len, arr[] = { 2147483647, 1, 2, 3, 4, 5, 6, 7, 2147483647 }, k = 2;
    double *ans = medianSlidingWindow(arr, LEN(arr), k, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.00001);
    }
    free(ans);
}

START_TEST(test_failed_1) {
    double target[] = { 7, 9, 3, 8, 0, 2, 4, 8, 3, 9 };
    int len, arr[] = { 7, 9, 3, 8, 0, 2, 4, 8, 3, 9 }, k = 1;
    double *ans = medianSlidingWindow(arr, LEN(arr), k, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.00001);
    }
    free(ans);
}

START_TEST(test_failed_2) {
    double target[] = { 5.5, 5.0, 7.0, 4.5, 5.5, 6.0, 5.0 };
    int len, arr[] = { 6, 5, 9, 5, 4, 9, 1, 7, 5, 5 }, k = 4;
    double *ans = medianSlidingWindow(arr, LEN(arr), k, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.00001);
    }
    free(ans);
}
START_TEST(test_failed_3) {
    int len, k = 321;
    int arr[] = {
        16807,     282475249, 622650073, 984943658, 144108930, 470211272, 101027544, 457850878, 458777923, 7237709,
        823564440, 115438165, 784484492, 74243042,  114807987, 137522503, 441282327, 16531729,  823378840, 143542612,
        896544303, 474833169, 264817709, 998097157, 817129560, 131570933, 197493099, 404280278, 893351816, 505795335,
        954899097, 636807826, 563613512, 101929267, 580723810, 704877633, 358580979, 624379149, 128236579, 784558821,
        530511967, 110010672, 551901393, 617819336, 399125485, 156091745, 356425228, 899894091, 585640194, 937186357,
        646035001, 25921153,  510616708, 590357944, 771515668, 357571490, 44788124,  927702196, 952509530, 130060903,
        942727722, 83454666,  108728549, 685118024, 118797801, 60806853,  571540977, 194847408, 35308228,  158374933,
        75260298,  824938981, 595028635, 962408013, 137623865, 997389814, 20739063,  107554536, 635339425, 654001669,
        777724115, 269220094, 34075629,  478446501, 864546517, 351934195, 581030105, 557810404, 146319451, 908194298,
        500782188, 657821123, 753799505, 102246882, 269406752, 816731566, 884936716, 807130337, 578354438, 892053144,
        153851501, 4844897,   616783871, 382955828, 330111137, 227619358, 723153177, 70982397,  147722294, 70477904,
        51621609,  606946231, 190959745, 912844175, 341853635, 808266298, 343098142, 456880399, 534827968, 280090412,
        195400260, 589673557, 6441594,   889688008, 57716395,  524325968, 14119113,  515204530, 388471006, 681910962,
        904797942, 400285365, 322842082, 463179852, 828530767, 832633821, 73185695,  316824712, 260973671, 815859901,
        267248590, 51724831,  194314738, 318153057, 111631616, 877819790, 304555640, 213110679, 541437335, 49077006,
        996497972, 63936098,  270649095, 428975319, 685583454, 351345223, 272112289, 398556760, 334948905, 724586126,
        532236123, 23129506,  836045813, 436476770, 60935238,  936329094, 915896220, 304987844, 34712366,  881140534,
        281725226, 901915394, 197941363, 348318738, 152607844, 784559590, 543436550, 290145159, 681808623, 977764947,
        750597385, 971307217, 737195272, 755539,    399399247, 462242385, 459413496, 951894885, 537140623, 848682420,
        12028144,  86531968,  289335735, 755699915, 623161625, 992663534, 43046042,  358796011, 943454679, 771024152,
        479575244, 507977295, 119878818, 49590396,  828087692, 621301815, 154112991, 104740033, 222122669, 889119397,
        238489553, 882410547, 944975825, 567121210, 866729662, 536830211, 719533808, 517273377, 592822761, 41000625,
        902737335, 127401868, 994977995, 140002776, 532062767, 49997439,  433829874, 464689331, 428540556, 968456301,
        859468872, 911300560, 168120094, 298918984, 967113755, 124639789, 462851407, 957828015, 678030193, 105222769,
        893015680, 944303455, 4016855,   732267506, 784170963, 454233502, 145586676, 329863108, 353963249, 323602331,
        1277844,   1887638,   660760808, 561939997, 685428651, 897054849, 465645203, 461495731, 440796531, 796198014,
        522395419, 779636775, 203042009, 175530180, 640687929, 351995223, 459244054, 458588260, 174076737, 834991545,
        44747317,  34837525,  837204200, 578134256, 486421564, 609960597, 668306648, 683337704, 907225550, 605925150,
        416541976, 24301412,  411938554, 111482797, 524102504, 760348381, 293034748, 855007065, 290659378, 379847699,
        778878209, 338725129, 121578553, 552265483, 501650447, 218264607, 471180773, 363045322, 494664305, 706755176,
        495170053, 616927224, 437784630, 360280366, 121205400, 284660444, 487495370, 684570285, 502883016, 252193898,
        637608155, 129841133, 189515557, 262696576, 707953178, 509658266, 307187357, 347221711, 42227878,  847320614,
        746474819, 195795737, 586983133, 678620591, 290623720, 135048762, 667306633, 262976197, 112576031, 925238588,
        555860589, 795054873, 843998877, 959637304, 21979358,  832861200, 599777254, 168068960, 794014915, 545293947,
        442645480, 452207730, 103669955, 564674546, 547837107, 28841238,  989340000, 18984926,  690545035, 988774857,
        110561113, 420250114, 862929593, 300601360, 118498354, 322968418, 439025357, 738342585, 163313729, 122721015,
        780776563, 32106102,  588860917, 380786643, 172819419, 971062967, 572547747, 83245269,  529855395, 812423303,
        490404473, 978719103, 754711748, 47424385,  345205658, 518163459, 520045406, 937673930, 250739824, 614285132,
        129300973, 493959603, 600246897, 618907920, 367603950, 9135231,   64488480,  171620203, 350213900, 939824520,
        681462533, 603481258, 937217003, 13618676,  255820950, 113423934, 143558780, 168279879, 836941832, 463482574,
        828433549, 346174542, 415306249
    };
    double target[] = { 462851407, 462851407, 463179852, 463179852, 462851407, 462851407, 462851407, 462851407,
                        462851407, 463179852, 464689331, 464689331, 465645203, 465645203, 465645203, 471180773,
                        474833169, 474833169, 478446501, 478446501, 478446501, 474833169, 471180773, 478446501,
                        478446501, 471180773, 478446501, 478446501, 479575244, 479575244, 478446501, 471180773,
                        471180773, 465645203, 465645203, 464689331, 463179852, 464689331, 463179852, 463179852,
                        463179852, 462851407, 463179852, 462851407, 462242385, 462851407, 463179852, 463179852,
                        463179852, 463179852, 463179852, 463179852, 464689331, 463179852, 462851407, 462851407,
                        463179852, 464689331, 463179852, 463179852, 463179852, 463179852, 464689331, 465645203,
                        464689331, 464689331, 464689331, 463179852, 463179852, 464689331, 465645203, 471180773,
                        471180773, 465645203, 464689331, 464689331, 463179852, 463179852, 464689331, 463482574,
                        463482574, 463179852, 463179852 };

    double *ans = medianSlidingWindow(arr, LEN(arr), k, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.00001);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_overflow);
    tcase_add_test(t, test_official);
}