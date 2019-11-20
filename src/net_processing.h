// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#ifndef ILCOIN_NET_PROCESSING_H
#define ILCOIN_NET_PROCESSING_H

#include "net.h"
#include "validationinterface.h"

/** Default for -maxorphantx, maximum number of orphan transactions kept in memory */
static const unsigned int DEFAULT_MAX_ORPHAN_TRANSACTIONS = 100;
/** Expiration time for orphan transactions in seconds */
static const int64_t ORPHAN_TX_EXPIRE_TIME = 20 * 60;
/** Minimum time between orphan transactions expire time checks in seconds */
static const int64_t ORPHAN_TX_EXPIRE_INTERVAL = 5 * 60;
/** Default number of orphan+recently-replaced txn to keep around for block reconstruction */
static const unsigned int DEFAULT_BLOCK_RECONSTRUCTION_EXTRA_TXN = 100;

/** Register with a network node to receive its signals */
void RegisterNodeSignals(CNodeSignals& nodeSignals);
/** Unregister a network node */
void UnregisterNodeSignals(CNodeSignals& nodeSignals);

class PeerLogicValidation : public CValidationInterface {
private:
    CConnman* connman;

public:
    PeerLogicValidation(CConnman* connmanIn);

    virtual void SyncTransaction(const CTransaction& tx, const CBlockIndex* pindex, int nPosInBlock);
    virtual void SyncTransaction2(const CTransaction& tx, const CMiniBlockIndex* pindex, int nPosInBlock);
    virtual void UpdatedBlockTip(const CBlockIndex *pindexNew, const CBlockIndex *pindexFork, bool fInitialDownload);
    virtual void UpdatedMiniBlockTip(const CMiniBlockIndex *pindexNew, const CMiniBlockIndex *pindexFork, bool fInitialDownload);
    virtual void BlockChecked(const CBlock& block, const CValidationState& state);
    virtual void BlockChecked2(const CBlock2& block, const CValidationState& state);
    virtual void BlockChecked3(const CBlock3& block, const CValidationState& state);
    virtual void NewPoWValidBlock(const CBlockIndex *pindex, const std::shared_ptr<const CBlock>& pblock);
    virtual void NewPoWValidBlock2(const CBlockIndex *pindex, const std::shared_ptr<const CBlock2>& pblock);
    virtual void NewPoWValidBlock3(const CMiniBlockIndex *pindex, const std::shared_ptr<const CBlock3>& pblock);
    virtual void NewPoWValidBlock4(const CBlockIndex *pindex, const std::shared_ptr<const CBlock3>& pblock);
};

struct CNodeStateStats {
    int nMisbehavior;
    int nSyncHeight;
    int nCommonHeight;
    int nSyncMiniHeight;
    int nCommonMiniHeight;
    std::vector<int> vHeightInFlight;
};

/** Get statistics from node state */
bool GetNodeStateStats(NodeId nodeid, CNodeStateStats &stats);
/** Increase a node's misbehavior score. */
void Misbehaving(NodeId nodeid, int howmuch);

/** Process protocol messages received from a given node */
bool ProcessMessages(CNode* pfrom, CConnman& connman, const std::atomic<bool>& interrupt);
/**
 * Send queued protocol messages to be sent to a give node.
 *
 * @param[in]   pto             The node which we are sending messages to.
 * @param[in]   connman         The connection manager for that node.
 * @param[in]   interrupt       Interrupt condition for processing threads
 * @return                      True if there is more work to be done
 */
bool SendMessages(CNode* pto, CConnman& connman, const std::atomic<bool>& interrupt);

#endif // ILCOIN_NET_PROCESSING_H
