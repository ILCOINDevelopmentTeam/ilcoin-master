// Copyright (c) 2015 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

/**
 * Functionality for communicating with Tor.
 */
#ifndef ILCOIN_TORCONTROL_H
#define ILCOIN_TORCONTROL_H

#include "scheduler.h"

extern const std::string DEFAULT_TOR_CONTROL;
static const bool DEFAULT_LISTEN_ONION = true;

void StartTorControl(boost::thread_group& threadGroup, CScheduler& scheduler);
void InterruptTorControl();
void StopTorControl();

#endif /* ILCOIN_TORCONTROL_H */
