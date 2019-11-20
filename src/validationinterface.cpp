// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#include "validationinterface.h"

static CMainSignals g_signals;

CMainSignals& GetMainSignals()
{
    return g_signals;
}

void RegisterValidationInterface(CValidationInterface* pwalletIn) {
    g_signals.UpdatedBlockTip.connect(boost::bind(&CValidationInterface::UpdatedBlockTip, pwalletIn, _1, _2, _3));
    g_signals.UpdatedMiniBlockTip.connect(boost::bind(&CValidationInterface::UpdatedMiniBlockTip, pwalletIn, _1, _2, _3));
    g_signals.SyncTransaction.connect(boost::bind(&CValidationInterface::SyncTransaction, pwalletIn, _1, _2, _3));
    g_signals.SyncTransaction2.connect(boost::bind(&CValidationInterface::SyncTransaction2, pwalletIn, _1, _2, _3));
    g_signals.UpdatedTransaction.connect(boost::bind(&CValidationInterface::UpdatedTransaction, pwalletIn, _1));
    g_signals.SetBestChain.connect(boost::bind(&CValidationInterface::SetBestChain, pwalletIn, _1));
    g_signals.Inventory.connect(boost::bind(&CValidationInterface::Inventory, pwalletIn, _1));
    g_signals.Broadcast.connect(boost::bind(&CValidationInterface::ResendWalletTransactions, pwalletIn, _1, _2));
    g_signals.BlockChecked.connect(boost::bind(&CValidationInterface::BlockChecked, pwalletIn, _1, _2));
    g_signals.BlockChecked2.connect(boost::bind(&CValidationInterface::BlockChecked2, pwalletIn, _1, _2));
    g_signals.BlockChecked3.connect(boost::bind(&CValidationInterface::BlockChecked3, pwalletIn, _1, _2));
    g_signals.ScriptForMining.connect(boost::bind(&CValidationInterface::GetScriptForMining, pwalletIn, _1));
    g_signals.BlockFound.connect(boost::bind(&CValidationInterface::ResetRequestCount, pwalletIn, _1));
    g_signals.NewPoWValidBlock.connect(boost::bind(&CValidationInterface::NewPoWValidBlock, pwalletIn, _1, _2));
    g_signals.NewPoWValidBlock2.connect(boost::bind(&CValidationInterface::NewPoWValidBlock2, pwalletIn, _1, _2));
    g_signals.NewPoWValidBlock3.connect(boost::bind(&CValidationInterface::NewPoWValidBlock3, pwalletIn, _1, _2));
    g_signals.NewPoWValidBlock4.connect(boost::bind(&CValidationInterface::NewPoWValidBlock4, pwalletIn, _1, _2));
}

void UnregisterValidationInterface(CValidationInterface* pwalletIn) {
    g_signals.BlockFound.disconnect(boost::bind(&CValidationInterface::ResetRequestCount, pwalletIn, _1));
    g_signals.ScriptForMining.disconnect(boost::bind(&CValidationInterface::GetScriptForMining, pwalletIn, _1));
    g_signals.BlockChecked.disconnect(boost::bind(&CValidationInterface::BlockChecked, pwalletIn, _1, _2));
    g_signals.BlockChecked2.disconnect(boost::bind(&CValidationInterface::BlockChecked2, pwalletIn, _1, _2));
    g_signals.BlockChecked3.disconnect(boost::bind(&CValidationInterface::BlockChecked3, pwalletIn, _1, _2));
    g_signals.Broadcast.disconnect(boost::bind(&CValidationInterface::ResendWalletTransactions, pwalletIn, _1, _2));
    g_signals.Inventory.disconnect(boost::bind(&CValidationInterface::Inventory, pwalletIn, _1));
    g_signals.SetBestChain.disconnect(boost::bind(&CValidationInterface::SetBestChain, pwalletIn, _1));
    g_signals.UpdatedTransaction.disconnect(boost::bind(&CValidationInterface::UpdatedTransaction, pwalletIn, _1));
    g_signals.SyncTransaction.disconnect(boost::bind(&CValidationInterface::SyncTransaction, pwalletIn, _1, _2, _3));
    g_signals.SyncTransaction2.disconnect(boost::bind(&CValidationInterface::SyncTransaction2, pwalletIn, _1, _2, _3));
    g_signals.UpdatedBlockTip.disconnect(boost::bind(&CValidationInterface::UpdatedBlockTip, pwalletIn, _1, _2, _3));
    g_signals.UpdatedMiniBlockTip.disconnect(boost::bind(&CValidationInterface::UpdatedMiniBlockTip, pwalletIn, _1, _2, _3));
    g_signals.NewPoWValidBlock.disconnect(boost::bind(&CValidationInterface::NewPoWValidBlock, pwalletIn, _1, _2));
    g_signals.NewPoWValidBlock2.disconnect(boost::bind(&CValidationInterface::NewPoWValidBlock2, pwalletIn, _1, _2));
    g_signals.NewPoWValidBlock3.disconnect(boost::bind(&CValidationInterface::NewPoWValidBlock3, pwalletIn, _1, _2));
    g_signals.NewPoWValidBlock4.disconnect(boost::bind(&CValidationInterface::NewPoWValidBlock4, pwalletIn, _1, _2));
}

void UnregisterAllValidationInterfaces() {
    g_signals.BlockFound.disconnect_all_slots();
    g_signals.ScriptForMining.disconnect_all_slots();
    g_signals.BlockChecked.disconnect_all_slots();
    g_signals.BlockChecked2.disconnect_all_slots();
    g_signals.BlockChecked3.disconnect_all_slots();
    g_signals.Broadcast.disconnect_all_slots();
    g_signals.Inventory.disconnect_all_slots();
    g_signals.SetBestChain.disconnect_all_slots();
    g_signals.UpdatedTransaction.disconnect_all_slots();
    g_signals.SyncTransaction.disconnect_all_slots();
    g_signals.SyncTransaction2.disconnect_all_slots();
    g_signals.UpdatedBlockTip.disconnect_all_slots();
    g_signals.UpdatedMiniBlockTip.disconnect_all_slots();
    g_signals.NewPoWValidBlock.disconnect_all_slots();
    g_signals.NewPoWValidBlock2.disconnect_all_slots();
    g_signals.NewPoWValidBlock3.disconnect_all_slots();
    g_signals.NewPoWValidBlock4.disconnect_all_slots();
}
