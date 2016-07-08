#pragma once
#include <QString>
#include <QMap>
#include <QSharedPointer>
#include <QStringList>
#include <functional>
#include "exception.h"

namespace Console {
    class Operations;
}

namespace ConnectionsTree {

    class KeyItem;
    class NamespaceItem;

    class Operations
    {
        ADD_EXCEPTION
    public:

        /**
         * List of databases with keys counters
         * @emit databesesLoaded
         **/        
        virtual void getDatabases(std::function<void(QMap<int, int>)>) = 0;

        /**
         * @brief getDatabaseKeys
         * @param dbIndex
         */        
        virtual void getDatabaseKeys(uint dbIndex, std::function<void(const QList<QByteArray>&, const QString&)>) = 0;

        /**
         * Cancel all operations & close connection
         * @brief disconnect
         */
        virtual void disconnect() = 0;

        /**
         * @brief getNamespaceSeparator
         * @return
         */
        virtual QString getNamespaceSeparator() = 0;

        virtual void openKeyTab(KeyItem& key, bool openInNewTab) = 0;

        virtual void openConsoleTab() = 0;

        virtual void openNewKeyDialog(int dbIndex, std::function<void()> callback,
                                      QString keyPrefix = QString()) = 0;

        virtual void notifyDbWasUnloaded(int dbIndex) = 0;

        virtual void deleteDbKey(ConnectionsTree::KeyItem& key, std::function<void(const QString&)> callback) = 0;

        virtual void deleteDbNamespace(ConnectionsTree::NamespaceItem& ns) = 0;

        virtual ~Operations() {}

    };
}
