// Copyright (c) 2016 The Ilcoin Core developers
// All Rights Reserved. Ilgamos International 2017©

#ifndef ILCOIN_QT_TEST_RPC_NESTED_TESTS_H
#define ILCOIN_QT_TEST_RPC_NESTED_TESTS_H

#include <QObject>
#include <QTest>

#include "txdb.h"
#include "txmempool.h"

class RPCNestedTests : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
    void rpcNestedTests();

private:
    CCoinsViewDB *pcoinsdbview;
};

#endif // ILCOIN_QT_TEST_RPC_NESTED_TESTS_H
