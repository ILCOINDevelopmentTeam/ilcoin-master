// Copyright (c) 2009-2016 The Ilcoin Core developers
// All Rights Reserved. Ilgamos International 2017©

#ifndef ILCOIN_QT_TEST_COMPATTESTS_H
#define ILCOIN_QT_TEST_COMPATTESTS_H

#include <QObject>
#include <QTest>

class CompatTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void bswapTests();
};

#endif // ILCOIN_QT_TEST_COMPATTESTS_H
