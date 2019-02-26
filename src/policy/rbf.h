// Copyright (c) 2016 The Ilcoin Core developers
// All Rights Reserved. Ilgamos International 2017©

#ifndef ILCOIN_POLICY_RBF_H
#define ILCOIN_POLICY_RBF_H

#include "txmempool.h"

enum RBFTransactionState {
    RBF_TRANSACTIONSTATE_UNKNOWN,
    RBF_TRANSACTIONSTATE_REPLACEABLE_BIP125,
    RBF_TRANSACTIONSTATE_FINAL
};

// Check whether the sequence numbers on this transaction are signaling
// opt-in to replace-by-fee, according to BIP 125
bool SignalsOptInRBF(const CTransaction &tx);

// Determine whether an in-mempool transaction is signaling opt-in to RBF
// according to BIP 125
// This involves checking sequence numbers of the transaction, as well
// as the sequence numbers of all in-mempool ancestors.
RBFTransactionState IsRBFOptIn(const CTransaction &tx, CTxMemPool &pool);

#endif // ILCOIN_POLICY_RBF_H
