// Copyright (c) 2009-2016 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#ifndef ILCOIN_CHECKPOINTS_H
#define ILCOIN_CHECKPOINTS_H

#include "uint256.h"

#include <map>

class CBlockIndex;
struct CCheckpointData;

/**
 * Block-chain checkpoints are compiled-in sanity checks.
 * They are updated every release or three.
 */
namespace Checkpoints
{

//! Returns last CBlockIndex* in mapBlockIndex that is a checkpoint
CBlockIndex* GetLastCheckpoint(const CCheckpointData& data);

} //namespace Checkpoints

#endif // ILCOIN_CHECKPOINTS_H
