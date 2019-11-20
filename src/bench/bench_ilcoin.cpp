// Copyright (c) 2015-2016 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#include "bench.h"

#include "key.h"
#include "validation.h"
#include "util.h"

int
main(int argc, char** argv)
{
    ECC_Start();
    SetupEnvironment();
    fPrintToDebugLog = false; // don't want to write to debug.log file

    benchmark::BenchRunner::RunAll();

    ECC_Stop();
}
