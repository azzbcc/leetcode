/**
 * failed_01.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/2 下午6:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */

int arr[] = {
    42,   10,   11,   60,   65,   50,   98,   66,   84,   35,   97,   -6,   null, -1,   73,   2,    61,   8,    20,
    11,   21,   13,   50,   88,   89,   20,   59,   65,   66,   null, 81,   -7,   12,   20,   -5,   82,   -8,   96,
    44,   58,   91,   31,   65,   29,   3,    93,   74,   null, null, 10,   -4,   91,   55,   85,   20,   52,   18,
    null, null, 11,   6,    91,   6,    58,   82,   null, null, 21,   null, 84,   null, 7,    31,   null, -9,   57,
    32,   94,   61,   44,   61,   35,   31,   -7,   54,   15,   75,   21,   -9,   65,   57,   74,   null, -2,   89,
    24,   6,    95,   null, null, 47,   null, null, 79,   null, 36,   31,   79,   86,   9,    5,    86,   92,   -4,
    83,   76,   3,    24,   10,   1,    10,   72,   95,   43,   0,    null, 38,   41,   40,   -6,   10,   93,   62,
    94,   82,   4,    -3,   25,   91,   19,   36,   null, 95,   37,   67,   13,   15,   18,   39,   57,   13,   64,
    50,   null, null, 26,   -3,   -7,   99,   null, -9,   77,   16,   91,   9,    null, null, null, 26,   null, 78,
    83,   19,   76,   92,   74,   96,   46,   14,   null, null, 8,    98,   null, null, 26,   null, -7,   64,   39,
    91,   79,   60,   80,   10,   3,    -2,   29,   85,   53,   70,   50,   24,   null, 56,   null, null, 33,   null,
    -5,   71,   8,    62,   72,   35,   83,   null, null, null, 14,   85,   -5,   17,   null, 5,    2,    14,   -8,
    3,    73,   49,   null, 89,   null, 84,   null, 85,   -3,   16,   8,    -9,   null, null, 91,   18,   76,   null,
    5,    58,   58,   4,    null, null, null, null, 95,   null, -3,   82,   99,   6,    null, null, 49,   58,   -3,
    54,   91,   63,   null, 12,   null, 26,   34,   64,   93,   null, null, null, null, 25,   -9,   91,   64,   33,
    76,   27,   null, null, 80,   null, null, null, 50,   68,   null, null, null, 10,   null, null, 60,   null, null,
    50,   8,    null, 30,   35,   36,   5,    17,   22,   61,   38,   40,   null, 12,   98,   68,   65,   60,   48,
    null, 20,   44,   20,   59,   78,   10,   91,   81,   8,    3,    27,   61,   null, 69,   null, 53,   null, null,
    null, null, null, 92,   null, null, null, 99,   91,   15,   71,   21,   66,   37,   5,    null, null, null, 12,
    52,   null, null, 7,    69,   28,   null, null, 68,   13,   94,   76,   null, null, null, 82,   -7,   94,   null,
    null, null, 42,   null, 3,    null, 22,   null, 25,   null, 89,   99,   null, 74,   60,   93,   25,   75,   56,
    null, 14,   null, 1,    24,   6,    null, null, null, null, -1,   null, null, 66,   3,    73,   91,   60,   null,
    null, 16,   42,   17,   81,   14,   96,   33,   null, 55,   null, null, -9,   67,   4,    9,    53,   null, null,
    null, null, null, null, null, null, null, 42,   96,   null, 29,   16,   59,   null, -3,   56,   90,   null, 72,
    null, null, 87,   null, null, null, null, null, null, null, null, null, 75,   null, null, 54,   null, 4,    39,
    -2,   null, 44,   80,   14,   null, 95,   8,    76,   19,   null, null, null, null, null, null, null, 66,   null,
    68,   92,   94,   5,    8,    96,   null, 80,   null, null, null, 40,   52,   30,   -7,   85,   null, 72,   90,
    1,    44,   4,    59,   19,   null, null, null, -9,   -8,   32,   63,   1,    null, 25,   null, 21,   33,   37,
    96,   -1,   43,   null, 83,   80,   65,   68,   99,   88,   null, 48,   77,   14,   null, 14,   8,    null, null,
    null, null, null, null, null, null, null, 89,   null, null, 14,   null, 37,   null, null, null, null, null, null,
    null, 20,   null, null, null, 61,   20,   null, null, null, 34,   50,   53,   null, null, 51,   null, 98,   25,
    42,   77,   59,   36,   18,   68,   4,    -5,   36,   71,   null, 37,   78,   null, null, null, null, null, null,
    null, null, null, null, 44,   74,   92,   null, null, 3,    21,   76,   32,   79,   null, 59,   3,    86,   -9,
    81,   -4,   null, null, null, 31,   61,   32,   null, null, 98,   null, -8,   5,    64,   null, 43,   32,   null,
    78,   null, 36,   null, null, null, 48,   null, null, null, 78,   71,   null, 71,   80,   12,   null, null, null,
    null, null, 29,   52,   1,    83,   5,    95,   2,    56,   93,   65,   86,   95,   null, null, null, null, 58,
    7,    null, 20,   -2,   84,   null, -9,   13,   null, null, 33,   null, 58,   null, null, 0,    38,   null, null,
    -9,   null, 88,   null, 78,   24,   null, 14,   null, null, 9,    75,   53,   -3,   null, 88,   71,   84,   76,
    62,   85,   53,   null, null, null, 79,   36,   -5,   null, 91,   57,   17,   null, null, null, null, 36,   12,
    -7,   51,   63,   -3,   77,   40,   13,   17,   10,   5,    89,   -4,   72,   27,   53,   null, 83,   65,   null,
    null, null, null, null, 33,   null, 96,   null, null, 85,   60,   9,    38,   23,   null, null, null, 39,   null,
    null, null, 16,   85,   99,   51,   null, null, null, null, null, null, 54,   null, null, 62,   null, null, 57,
    90,   61,   99,   69,   2,    23,   71,   35,   null, -4,   51,   -1,   null, 30,   3,    null, null, 17,   42,
    null, null, 77,   95,   39,   85,   null, -8,   43,   5,    86,   null, 33,   56,   47,   78,   9,    70,   57,
    3,    29,   71,   null, null, null, null, null, null, null, null, 47,   92,   85,   38,   -3,   null, null, 22,
    null, null, 34,   37,   null, 86,   79,   68,   84,   null, null, null, null, null, null, null, 78,   58,   null,
    null, 49,   null, null, 11,   null, null, null, null, null, null, null, 88,   65,   null, 50,   null, 52,   null,
    55,   null, 13,   0,    null, null, null, null, 30,   86,   60,   68,   48,   85,   null, null, null, 20,   null,
    null, null, 39,   52,   77,   62,   null, 82,   -6,   null, null, 60,   null, 71,   null, null, null, 39,   0,
    53,   null, null, 11,   null, null, null, 3,    85,   3,    78,   null, 78,   -1,   30,   72,   null, null, null,
    null, 35,   29,   40,   79,   86,   12,   21,   null, 48,   46,   70,   98,   62,   22,   93,   null, null, null,
    null, null, null, null, 45,   null, null, null, null, null, -6,   null, null, null, null, 71,   null, null, null,
    null, 68,   null, 41,   93,   null, null, 62,   78,   -7,   14,   null, 19,   16,   91,   null, null, null, null,
    null, 20,   90,   51,   42,   null, null, 93,   85,   null, null, 58,   9,    null, -3,   27,   86,   42,   null,
    null, null, null, null, 17,   null, null, null, null, 22,   -8,   93,   8,    49,   90,   null, null, 63,   19,
    39,   null, null, null, 17,   4,    54,   8,    -5,   76,   null, null, -9,   -6,   null, 34,   null, 51,   10,
    20,   null, 23,   14,   91,   26,   47,   null, 47,   67,   null, null, 26,   null, null, null, null, null, null,
    null, null, 34,   null, 15,   0,    85,   13,   3,    88,   86,   null, 80,   39,   33,   null, 52,   null, null,
    39,   null, -4,   21,   null, null, null, 2,    89,   null, null, -1,   -6,   null, 17,   -1,   65,   null, null,
    null, null, null, 19,   null, null, 63,   null, null, null, null, null, -1,   68,   null, null, null, null, null,
    null, null, null, 17,   null, null, null, 93,   42,   null, null, null, 12,   null, null, null, 92,   85,   82,
    8,    null, null, 34,   18,   90,   50,   null, 99,   89,   null, 19,   null, null, 78,   null, 74,   -2,   null,
    null, null, 63,   null, null, 38,   38,   null, null, null, null, null, null, null, null, null, null, 74,   null,
    8,    null, null, null, 49,   null, null, null, 21,   0,    null, 2,    60,   15,   36,   83,   59,   54,   null,
    -3,   null, null, null, -8,   null, 5,    49,   32,   null, null, null, null, null, 7,    null, null, null, 55,
    null, null, 26,   78,   98,   null, null, 57,   null, null, 83,   63,   null, null, null, null, 81,   null, null,
    33,   null, null, null, null, null, null, 16,   14,   null, null, -4,   44,   null, null, 37,   16,   16,   33,
    null, 84,   null, 25,   10,   null, null, 30,   null, null, null, null, null, null, 65,   null, null, null, 93,
    null, null, null, 44,   57,   12,   52,   -4,   67,   null, 49,   null, null, null, null, null, null, null, 64,
    17,   null, null, null, 83,   4,    61,   75,   null, null, null, null, null, null, 24,   null, 78,   -7,   null,
    -5,   null, null, 30,   79,   null, 44,   94,   55,   14,   59,   null, null, null, null, null, null, 60,   null,
    null, null, null, 25,   null, null, null, null, 97,   34,   null, null, null, null, 80,   67,   0,    null, 22,
    null, 96,   null, null, null, null, null, null, null, null, 47,   null, null, null, null, 89,   null, null, null,
    null, 43,   64,   null, null, 9,    null, null, 96,   37,   79,   null, null, null, 28,   81,   null, null, 5,
    null, null, 7,    96,   41,   82,   -6,   20,   null, null, null, 8,    null, null, null, null, null, null, null,
    null, null, 82,   8,    null, null, null, null, null, null, null, null, 39,   6,    null, null, null, null, 90,
    59,   -8,   null, null, null, null, null, 23,   null, null, null, 15,   89,   null, null, 86,   50,   40,   70,
    null, null, 32,   null, null, null, 44,   -2,   null, 38,   39,   null, null, null, null, null, null, null, null,
    null, 2,    null, null, null, null, 2,    null, null, 65,   47,   null, null, 62,   27,   62,   38,   31,   27,
    null, null, 37,   null, null, null, null, null, null, null, 62,   74,   86,   -7,   null, 23,   null, null, 56,
    null, null, null, 6,    null, 86,   72,   30,   null, null, 21,   41,   92,   null, null, null, null, 22,   null,
    74,   96,   87,   null, null, null, null, null, -7,   null, 51,   34,   80,   null, null, null, null, null, null,
    null, 16,   20,   null, null, 15,   81,   null, 55,   null, 61,   null, null, 22,   null, 5,    14,   null, 34,
    23,   null, 30,   null, 6,    64,   2,    65,   null, 54,   null, null, 14,   null, 0,    null, null, null, 26,
    null, null, 78,   null, 49,   null, null, 13,   null, null, null, 43,   null, null, -1,   41,   33,   null, 5,
    78,   null, null, null, null, null, null, null, null, null, null, 75,   null, null, null, null, null, null, 63,
    70,   null, null, null, null, null, 40,   null, null, null, 66,   null, null, 15,   null, 7,    43,   null, 60,
    12,   null, null, null, null, null, null, null, 19,   null, 74,   -5,   55,   null, null, null, null, 52,   -4,
    -5,   null, null, null, 65,   null, null, 67,   null, 3,    null, null, 95,   null, null, 36,   null, 81,   null,
    null, null, null, null, 88,   74,   null, 67,   null, null, null, null, 68,   null, null, null, null, 52,   null,
    null, 82,   90,   75,   25,   null, 23,   null, 68,   6,    11,   null, 59,   null, null, null, null, null, null,
    null, null, -2,   null, null, null, 61,   null, null, null, 32,   80,   null, null, null, 51,   6,    null, 91,
    null, null, 37,   null, 26,   null, 78,   null, null, null, null, null, null, null, 34,   null, null, null, null,
    null, null, 24,   31,   null, null, 99,   56,   null, null, 62,   12,   43,   null, null, null, null, null, null,
    33,   null, 68,   null, null, null, null, 53,   4,    65,   4,    null, 86,   null, 46,   -9,   null, null, 83,
    null, null, null, null, 93,   null, null, 78,   null, 63,   null, null, null, null, null, 67,   null, null, null,
    null, 72,   93,   25,   null, null, 27,   null, null, 92,   44,   null, null, null, null, 2,    9,    31,   null,
    null, 73,   92,   62,   86,   null, null, -6,   null, null, null, null, 58,   null, null, null, null, null, null,
    null, null, 54,   null, null, null, null, null, null, null, null, 16,   null, null, null, null, null, null, null,
    null, null, null, null, 28,   null, 48,   null, null, null, null, null, 26,   null, null, null, null, null, null,
    37,   66,   null, null, 92,   null, null, null, null, 86,   89,   null, null, null, null, null, null, 5,    85,
    null, null, 75,   null, 35,   null, null, null, null, null, null, null, 27,   null, null, null, null, null, null,
    67,   84,   94,   44,   null, null, null, null, null, null, null, null, null, null, 70,   null, null, 49,   null,
    null, 16,   null, null, null, null, null, null, null, 87,   null, -7,   52,   null, null, null, 67,   null, null,
    null, null, null, null, null, null, null, null, null, null, null, null, 80,   null, 76,   null, 25,   null, 91,
    null, 12,   41,   null, null, 26,   null, null, null, null, null, null, null, null, null, null, null, null, null,
    null, 94
};
char *target =
    "42(10(60(66(2()(81))(61(-7(11(79(8(30(4(29)(52()(88)))(39(1(65))(83(50(17(79))))))(35(-2(5(52))(95(55(93)(42(28("
    "13(24)(31)))(81)))))))(98(36(44(2(13)(0()(12)))(56))(80(93)(65(30)(86()(92(5(43)))))))(5(14(86(60(85()(7()(-1(99)("
    "56(28(49()(25)))))))(82(96(41)(33(62(48()(16()(91))))(12)))(41()(5(43)))))(68(8(82(78))(-6))))(95(48()(34(20)))("
    "85(18)(90(8))))))))(86))(6(9(26(17(95)(8))(22(76(58)(7()(20(50))))(19()(20)))))(5(-7(61)(38))(64(40)))))(12(91(86("
    "39(12()(66(-2()(39(99)(89)))(84(52()(19))(77))))(98()(68()(-9(62(78(82)(8()(75))))))))(91(68(92(13(82(74)(-2))(-6)"
    "))(94()(33)))(65(5()(58(60()(63))))(8))))(92(79(60(96(0(71))(38)))(48(80)))(60()(20))))(6(-4(80(44(40(-9(39(38)("
    "38(39)(6)))(0)))(52(88(53))))(20(30(78()(11))(24))(-7()(14()(3)))))(10(59(85))(78(72(9(85)(3(74)))(75(78(8))))(90("
    "53(78)(-1(49(90)(59(63()(33(26)))(70()(68))))))(-3(30)(72(21(-8))(0)))))))(83(3(10(1()(88))(44(71)(84(35()(2))(29("
    "60(23))(15)))))(91(4(76(40(36(15()(40))(89))(83))(79(59(86()(66))(50))(54(40(15(53)(4()(37))))(70(7(65(66))(4()("
    "92()(87()(12)))))(43()(86))))))(62(86()(-3))(12)))(59(85(21()(-8(32()(60()(46))))))(53(48()(5))(46(49(44(12(-9(86("
    ")(-7(41)))(89(52()(26(94)))))))(-2))(32()(38)))))))(-2(81(19))(8)))))))(84(8(20(58(76(29(3(-9()(79(70)(98)))(-8("
    "36(62()(7(39)))(22))(-5(93()(55)))))(27(32()(91))(63(57)(17))))(85(61(1))))(3(53(69(25)))(70(53(21(36(45))(12))("
    "33(-7)(51(-6(26)(78))))))))(82(24(50)(24))(10()(56(92(37(63)(-3()(71(98))))(96(77)(40)))))))(-5))(20(82(21(1)(10("
    "33))))(-8(84(72(-5(99(-1(13(68()(57(2(19()(83))))))(17(41)(93(83)(63()(2(74)(-5))))))(43(10)(5(62)(78))))(91()(83("
    "89(-7(81))(14()(33(65(55(93)))(47))))(-4()(19)))))(71(15(80(72(16)(91))(27))(65(53)))(71(68(83()(20(16)(14(62()("
    "52()(78)))(27(-4()(63(5)(85(67))))(-5)))))(65(90)(51(-4(62)(38()(65)))(44(31)(27(67()(67)))))))(99))))(95(8(21(88)"
    ")(66(48()(33(42)))(77()(96()(93(37)(16(37(3))))))))(62(37(14))(5(14(85(85(16)(33)))(60()(58()(84))))(8(9(9()(25("
    "62()(95))(74))))(38(-3(10(86(36(72(75))(93(35))))(-7(81(25)))))(27()(30()(23)))))))))))))(65(35(11(96(7(43(72)(35("
    ")(12)))(0(83(52))))(31()(38)))(44()(-9(41(14()(7))(85(69)(28()(89(23(86)(42))))))(40(-5)(17(68)(13(14)))))))(21("
    "58(57(-6()(5(94(37(39)))(76)))(10(2)(14()(82))))(32(93(-8(-7)(94(20)))(3))(62(73()(42))(49()(3(61(16)(85()(17)))("
    "20(99)(51)))))))(91(94(94()(89()(22)))(82()(84()(25()(34)))))(61(4()(85()(89(50)(53))))(-3(-3(99))(16(74(51(54(22("
    "65))(-8))))(60(98()(62(93(93(56)))(8)))(25))))))))(97(13(31(44(25(8(93(42(57(49(44)(57(6(88()(27))(74))))(90(12("
    "86()(67(92)(44(27))))(72))(52(30))))(90))(77(61(63(-4()(21(68)))(67(41)(92()(52))))(19()(49)))(99(39))))(25(59(69)"
    "(2(17)(4)))(36(23(54()(64))(8(17(22))))(71(-5)(76(83(74(82(2)(9))(90(31()(67))))(96(75()(73(84)(94)))(25(92(44()("
    "80)))(62))))(4(87()(23(86)))))))))(-9(75(18(35))(68(-4(-9(61)(75))(-6))(51()(34))))(56(4(-1()(51)))(-5(30(10(24(-"
    "7()(68()(-6)))))(20(78(51(6)(11))(34()(59(58))))(-7(80))))(3()(23()(-5)))))))(91))(61(19(91()(14(36)(71(17(14)(91("
    "30)(79)))(42(26()(44(16)(20)))(47(94)(55(15)(81(-2))))))))(18()(1()(37))))(36(76(24(78(77()(47(14()(55))(59()(61("
    "61)))))(95(67))))(6)))))(65(35()(95(5)(58)))(31(37(58(-1))(4()(66)))(67))))(50(29(-7(13)(15(95(3)(73()(44(39()(26)"
    ")(85))))))(54(18(-3(91(74()(-8))(92(43)(5)))(60))(82))(39(99(16(3(86(34)))(21(33(15(60))(0))(56(85()(25(22)))(13))"
    "))(42(76(47(3)(88(97(5(32)(80()(54()(70()(76)))))(14))(34()(34()(51)))))(78(86)))(32(9(80)(39(80(23(6)))(67(30(91)"
    "))))(70(33(0(6()(37))(64()(26(16)))))))))(6(17(79(57(52(22(2()(78))(65))))(3()(39(96()(54))))))(81(59(29()(-4))("
    "71(21)))(3))))))(3(15(57)(13(49(14(86)(-9))(96(81)(-4(47)(92(2)(89()(47))))))(58(33))))(75(64(-3(55()(31(85)(38(-"
    "1)(-6)))))(54()(-9(61(-3()(17(89(14)))))(32()(22(-1)(65()(43(0()(34)))))))))(50(91(67)(4(98)))(63(9(-8(34)(37))(5("
    ")(86()(19(64)))))(53(64(79)(68(63()(9(26))))))))))))))(11(50(-6(88(93(21)(-9(26()(12))(-3()(26))))(74(65(-7(34)("
    "64))(99(93()(42(43(84))(32)))))(57()(-9))))(89)))(98(-1(20(10(74(77()(25(96()(78))))(16(-9(29()(36))(16))(91(59()("
    "48(78)(58(-1)(68(96()(78))(37()(49))))))))))(-4(-2(91(64(-3)(56()(78)))(33(90(71(49)))))(9(76(72(71()(11))(80)))("
    "27()(87(12)))))(89)))(59(91(24()(26))(6()(78(80))))(55(95(83)(19(50)(68))))))(73(65(85()(47(76)(92()(10))))(20))("
    "66(52(79(74)(96(60()(75)))))(18(36(46()(50))(14(8(54))))(31))))))";