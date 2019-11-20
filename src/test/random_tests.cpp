// Copyright (c) 2017 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#include "random.h"

#include "test/test_ilcoin.h"

#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(random_tests, BasicTestingSetup)

BOOST_AUTO_TEST_CASE(osrandom_tests)
{
    BOOST_CHECK(Random_SanityCheck());
}

BOOST_AUTO_TEST_SUITE_END()

