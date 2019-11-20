// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#include "cleanse.h"

#include <openssl/crypto.h>

void memory_cleanse(void *ptr, size_t len)
{
    OPENSSL_cleanse(ptr, len);
}
