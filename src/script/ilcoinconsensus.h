// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#ifndef ILCOIN_ILCOINCONSENSUS_H
#define ILCOIN_ILCOINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_ILCOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/ilcoin-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBILCOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define ILCOINCONSENSUS_API_VER 1

typedef enum ilcoinconsensus_error_t
{
    ilcoinconsensus_ERR_OK = 0,
    ilcoinconsensus_ERR_TX_INDEX,
    ilcoinconsensus_ERR_TX_SIZE_MISMATCH,
    ilcoinconsensus_ERR_TX_DESERIALIZE,
    ilcoinconsensus_ERR_AMOUNT_REQUIRED,
    ilcoinconsensus_ERR_INVALID_FLAGS,
} ilcoinconsensus_error;

/** Script verification flags */
enum
{
    ilcoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    ilcoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    ilcoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    ilcoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    ilcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    ilcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    ilcoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    ilcoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = ilcoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | ilcoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               ilcoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | ilcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               ilcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | ilcoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not NULL, err will contain an error/success code for the operation
EXPORT_SYMBOL int ilcoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, ilcoinconsensus_error* err);

EXPORT_SYMBOL int ilcoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, ilcoinconsensus_error* err);

EXPORT_SYMBOL unsigned int ilcoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // ILCOIN_ILCOINCONSENSUS_H
