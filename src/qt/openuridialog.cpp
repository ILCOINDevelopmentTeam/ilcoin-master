// Copyright (c) 2011-2014 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#include "openuridialog.h"
#include "ui_openuridialog.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

OpenURIDialog::OpenURIDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenURIDialog)
{
    ui->setupUi(this);
#if QT_VERSION >= 0x040700
    ui->uriEdit->setPlaceholderText("ilcoin:");
#endif
}

OpenURIDialog::~OpenURIDialog()
{
    delete ui;
}

QString OpenURIDialog::getURI()
{
    return ui->uriEdit->text();
}

void OpenURIDialog::accept()
{
    SendCoinsRecipient rcp;
    if(GUIUtil::parseIlcoinURI(getURI(), &rcp))
    {
        /* Only accept value URIs */
        QDialog::accept();
    } else {
        ui->uriEdit->setValid(false);
    }
}

void OpenURIDialog::on_selectFileButton_clicked()
{
    QString filename = GUIUtil::getOpenFileName(this, tr("Select payment request file to open"), "", "", NULL);
    if(filename.isEmpty())
        return;
    QUrl fileUri = QUrl::fromLocalFile(filename);
    ui->uriEdit->setText("ilcoin:?r=" + QUrl::toPercentEncoding(fileUri.toString()));
}
