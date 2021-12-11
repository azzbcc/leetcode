/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/11 上午9:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0911.c"

START_TEST(test_official) {
    int persons[] = { 0, 1, 1, 0, 0, 1, 0 };
    int times[]   = { 0, 5, 10, 15, 20, 25, 30 };

    TopVotedCandidate *candidate = topVotedCandidateCreate(persons, LEN(persons), times, LEN(times));
    ck_assert_ptr_nonnull(candidate);

    ck_assert_int_eq(topVotedCandidateQ(candidate, 3), 0);
    ck_assert_int_eq(topVotedCandidateQ(candidate, 12), 1);
    ck_assert_int_eq(topVotedCandidateQ(candidate, 25), 1);
    ck_assert_int_eq(topVotedCandidateQ(candidate, 15), 0);
    ck_assert_int_eq(topVotedCandidateQ(candidate, 24), 0);
    ck_assert_int_eq(topVotedCandidateQ(candidate, 8), 1);

    topVotedCandidateFree(candidate);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}