// Copyright (c) 2011-2014 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#ifndef ILCOIN_QT_MACNOTIFICATIONHANDLER_H
#define ILCOIN_QT_MACNOTIFICATIONHANDLER_H

#include <QObject>

/** Macintosh-specific notification handler (supports UserNotificationCenter and Growl).
 */
class MacNotificationHandler : public QObject
{
    Q_OBJECT

public:
    /** shows a 10.8+ UserNotification in the UserNotificationCenter
     */
    void showNotification(const QString &title, const QString &text);

    /** executes AppleScript */
    void sendAppleScript(const QString &script);

    /** check if OS can handle UserNotifications */
    bool hasUserNotificationCenterSupport(void);
    static MacNotificationHandler *instance();
};


#endif // ILCOIN_QT_MACNOTIFICATIONHANDLER_H
