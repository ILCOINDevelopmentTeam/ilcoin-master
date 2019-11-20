// Copyright (c) 2015 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#ifndef ILCOIN_MERKLE
#define ILCOIN_MERKLE

#include <stdint.h>
#include <vector>

#include "primitives/transaction.h"
#include "primitives/block.h"
#include "uint256.h"

uint256 ComputeMerkleRoot(const std::vector<uint256>& leaves, bool* mutated = NULL);
std::vector<uint256> ComputeMerkleBranch(const std::vector<uint256>& leaves, uint32_t position);
uint256 ComputeMerkleRootFromBranch(const uint256& leaf, const std::vector<uint256>& branch, uint32_t position);

/*
 * Compute the Merkle root of the transactions in a block.
 * *mutated is set to true if a duplicated subtree was found.
 */
uint256 BlockMerkleRoot(const CBlock& block, bool* mutated = NULL);
uint256 BlockMerkleRoot(const CBlock2& block, bool* mutated = NULL);
uint256 BlockMerkleRoot(const CBlock3& block, bool* mutated = NULL);

/*
 * Compute the Merkle root of the witness transactions in a block.
 * *mutated is set to true if a duplicated subtree was found.
 */
uint256 BlockWitnessMerkleRoot(const CBlock& block, bool* mutated = NULL);
uint256 BlockWitnessMerkleRoot(const CBlock2& block, bool* mutated = NULL);
uint256 BlockWitnessMerkleRoot(const CBlock3& block, bool* mutated = NULL);

/*
 * Compute the Merkle branch for the tree of transactions in a block, for a
 * given position.
 * This can be verified using ComputeMerkleRootFromBranch.
 */
std::vector<uint256> BlockMerkleBranch(const CBlock& block, uint32_t position);

#endif
