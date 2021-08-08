/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/19 下午12:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1603.c"

START_TEST(test_official) {
    ParkingSystem *park = parkingSystemCreate(1, 1, 0);

    ck_assert_int_eq(true, parkingSystemAddCar(park, 1));
    ck_assert_int_eq(true, parkingSystemAddCar(park, 2));
    ck_assert_int_eq(false, parkingSystemAddCar(park, 3));
    ck_assert_int_eq(false, parkingSystemAddCar(park, 1));
    parkingSystemFree(park);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}