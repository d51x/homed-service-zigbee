#ifndef ACTION_H
#define ACTION_H

#include <QSharedPointer>
#include <QVariant>
#include "property.h"

class ActionObject;
typedef QSharedPointer <ActionObject> Action;

class ActionObject : public MetaObject
{

public:

    ActionObject(const QString &name, quint16 clusterId, quint16 manufacturerCode = 0, QList <quint16> attributes = {}) :
        MetaObject(name), m_clusterId(clusterId), m_manufacturerCode(manufacturerCode), m_transactionId(0), m_attributes(attributes) {}

    ActionObject(const QString &name, quint16 clusterId, quint16 manufacturerCode, quint16 attributeId) :
        MetaObject(name), m_clusterId(clusterId), m_manufacturerCode(manufacturerCode), m_transactionId(0), m_attributes({attributeId}) {}

    ActionObject(const QString &name, quint16 clusterId, quint16 manufacturerCode, QList <QString> actions) :
        MetaObject(name), m_clusterId(clusterId), m_manufacturerCode(manufacturerCode), m_transactionId(0), m_actions(actions) {}

    virtual ~ActionObject(void) {}
    virtual QByteArray request(const QString &name, const QVariant &data) = 0;

    inline quint16 clusterId(void) { return m_clusterId; }
    inline quint16 manufacturerCode(void) { return m_manufacturerCode; }

    inline QList <quint16> &attributes(void) { return m_attributes; }
    inline QList <QString> &actions(void) { return m_actions; }

    static void registerMetaTypes(void);

protected:

    quint16 m_clusterId, m_manufacturerCode;
    quint8 m_transactionId;

    QList <quint16> m_attributes;
    QList <QString> m_actions;

    Property endpointProperty(const QString &name = QString());

};

#endif
