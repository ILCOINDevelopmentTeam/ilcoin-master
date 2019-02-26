// Copyright (c) 2016 The Ilcoin Core developers
// All Rights Reserved. Ilgamos International 2017©

#ifndef ILCOIN_WALLET_TEST_FIXTURE_H
#define ILCOIN_WALLET_TEST_FIXTURE_H

#include "test/test_ilcoin.h"

/** Testing setup and teardown for wallet.
 */
struct WalletTestingSetup: public TestingSetup {
    WalletTestingSetup(const std::string& chainName = CBaseChainParams::MAIN);
    ~WalletTestingSetup();
};

#endif

