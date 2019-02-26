// Copyright (c) 2011-2014 The Ilcoin Core developers
// All Rights Reserved. Ilgamos International 2017©

#ifndef ILCOIN_QT_TRANSACTIONDESCDIALOG_H
#define ILCOIN_QT_TRANSACTIONDESCDIALOG_H

#include <QDialog>

namespace Ui {
    class TransactionDescDialog;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog showing transaction details. */
class TransactionDescDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionDescDialog(const QModelIndex &idx, QWidget *parent = 0);
    ~TransactionDescDialog();

private:
    Ui::TransactionDescDialog *ui;
};

#endif // ILCOIN_QT_TRANSACTIONDESCDIALOG_H
