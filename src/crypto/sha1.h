// Copyright (c) 2014-2016 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#ifndef ILCOIN_CRYPTO_SHA1_H
#define ILCOIN_CRYPTO_SHA1_H

#include <stdint.h>
#include <stdlib.h>

/** A hasher class for SHA1. */
class CSHA1
{
private:
    uint32_t s[5];
    unsigned char buf[64];
    uint64_t bytes;

public:
    static const size_t OUTPUT_SIZE = 20;

    CSHA1();
    CSHA1& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
    CSHA1& Reset();
};

#endif // ILCOIN_CRYPTO_SHA1_H
