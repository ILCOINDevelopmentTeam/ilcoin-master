// Copyright (c) 2011-2014 The Ilcoin Core developers
// All Rights Reserved. Ilgamos International 2017©

#ifndef ILCOIN_QT_ILCOINADDRESSVALIDATOR_H
#define ILCOIN_QT_ILCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class IlcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit IlcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Ilcoin address widget validator, checks for a valid ilcoin address.
 */
class IlcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit IlcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // ILCOIN_QT_ILCOINADDRESSVALIDATOR_H
