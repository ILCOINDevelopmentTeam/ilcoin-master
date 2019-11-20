// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#ifndef ILCOIN_SCRIPT_SIGCACHE_H
#define ILCOIN_SCRIPT_SIGCACHE_H

#include "script/interpreter.h"

#include <vector>

// DoS prevention: limit cache size to 32MB (over 1000000 entries on 64-bit
// systems). Due to how we count cache size, actual memory usage is slightly
// more (~32.25 MB)
static const unsigned int DEFAULT_MAX_SIG_CACHE_SIZE = 32;
// Maximum sig cache size allowed
static const int64_t MAX_MAX_SIG_CACHE_SIZE = 16384;

class CPubKey;

class CachingTransactionSignatureChecker : public TransactionSignatureChecker
{
private:
    bool store;

public:
    CachingTransactionSignatureChecker(const CTransaction* txToIn, unsigned int nInIn, const CAmount& amountIn, bool storeIn, PrecomputedTransactionData& txdataIn) : TransactionSignatureChecker(txToIn, nInIn, amountIn, txdataIn), store(storeIn) {}

    bool VerifySignature(const std::vector<unsigned char>& vchSig, const CPubKey& vchPubKey, const uint256& sighash) const;
};

void InitSignatureCache();

#endif // ILCOIN_SCRIPT_SIGCACHE_H
