/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/8 上午10:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0299.c"

START_TEST(test_official_1) {
    char *secret = "1807", *guess = "7810";
    char *target = "1A3B", *ans = getHint(secret, guess);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *secret = "1123", *guess = "0111";
    char *target = "1A1B", *ans = getHint(secret, guess);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char *secret = "1", *guess = "0";
    char *target = "0A0B", *ans = getHint(secret, guess);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    char *secret = "1", *guess = "1";
    char *target = "1A0B", *ans = getHint(secret, guess);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    char *secret =
        "104554533550955863134513380686721962547908931821487533184706038889024161058638384987217652379475275523249"
        "895591025055758990853862423935558851779511101439291727685246864562481177633200239779689897556317844361901"
        "257950248858861891543644307595102987619333057755812469983720530390005821152956217553521171231801628142968"
        "044627198098678527026752792437085139273017481920290649616849913067638286893063229622205423811631890217170"
        "064949388641133027418234385715326595429607587886423117301878325564808085098866200611858667231926299855339"
        "987102407063115587551876836653615289968666702973375873151709676659930148790400315380045213383548064525372"
        "205551533925176015958574336236576510880473484387387464970390813805384448731499691179270227194904135828944"
        "120687137108230336321506111682968555908741225531351553678091912832683686800643438572185790425253149463550"
        "008659048090193176948048100384846363694365459965075447632483464590265820145510040596635721272464891500479"
        "7672559433879041653546077895815788973375525709931265007";
    char *guess =
        "794411102893265051727865659104079318920466137529975774341222899499317134715951263747567728617606921000311"
        "662444658025012254790307161520242618994133226492771053588727827131579031768461497394543425879772601709878"
        "212828038439963450455969831991539610718276889266820060852957655159956733862259805892214463363516708355955"
        "517569303785934501190059856702487585078281987419200177185999670090064747725087502481120720648560091314718"
        "490815853700830652692820882967599867767573151063061588739416498235187830559413099854760669437665394458186"
        "238525025838887748930367556797377261920296117774054674007555341709889937915377700712229817484735726527974"
        "662567667083607253883552070938756599529161801199477237527124366561254138307199707672879017863107940789848"
        "185836800402078421517308356881023619384212285524711489196761919588526338772359726675579754270003732437704"
        "725633520800703392381046402809003810613643489962960928018088881757311436093190726113539293285359335486095"
        "9442890959631958285909879113594006278416575494603366515";
    char *target = "108A837B", *ans = getHint(secret, guess);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}