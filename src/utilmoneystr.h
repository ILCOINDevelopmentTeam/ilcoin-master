// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Ilcoin Core developers
// All Rights Reserved. Ilgamos International 2017©

/**
 * Money parsing/formatting utilities.
 */
#ifndef ILCOIN_UTILMONEYSTR_H
#define ILCOIN_UTILMONEYSTR_H

#include <stdint.h>
#include <string>

#include "amount.h"

std::string FormatMoney(const CAmount& n);
bool ParseMoney(const std::string& str, CAmount& nRet);
bool ParseMoney(const char* pszIn, CAmount& nRet);

#endif // ILCOIN_UTILMONEYSTR_H
