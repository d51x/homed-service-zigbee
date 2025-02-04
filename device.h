#ifndef DEVICE_H
#define DEVICE_H

#define STORE_DATABASE_INTERVAL     60000
#define STORE_DATABASE_DELAY        20
#define STORE_PROPERTIES_DELAY      1000

#include <QDateTime>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "action.h"
#include "adapter.h"
#include "binding.h"
#include "expose.h"
#include "poll.h"
#include "property.h"
#include "reporting.h"

class EndpointObject;
typedef QSharedPointer <EndpointObject> Endpoint;

class DeviceObject;
typedef QSharedPointer <DeviceObject> Device;

enum class ZoneStatus
{
    Unknown,
    SetAddress,
    Enroll,
    Enrolled
};

enum class AvailabilityStatus
{
    Unknown,
    Online,
    Offline
};

class EndpointObject : public EndpointDataObject
{

public:

    EndpointObject(quint8 id, Device device, quint16 profileId = 0, quint16 deviceId = 0) :
        EndpointDataObject(profileId, deviceId), m_timer(new QTimer(this)), m_id(id), m_device(device), m_pollInterval(0), m_pollTime(0), m_colorCapabilities(0), m_zoneType(0), m_zoneStatus(ZoneStatus::Unknown), m_descriptorReceived(false), m_updated(false) {}

    inline QTimer *timer(void) { return m_timer; }

    inline quint8 id(void) { return m_id; }
    inline Device device(void) { return m_device; }

    inline quint32 pollInterval(void) { return m_pollInterval; }
    inline void setPollInterval(quint32 value) { m_pollInterval = value; }

    inline qint64 pollTime(void) { return m_pollTime; }
    inline void setPollTime(qint64 value) { m_pollTime = value; }

    inline quint16 colorCapabilities(void) { return m_colorCapabilities; }
    inline void setColorCapabilities(quint16 value) { m_colorCapabilities = value; }

    inline quint16 zoneType(void) { return m_zoneType; }
    inline void setZoneType(quint16 value) { m_zoneType = value; }

    inline ZoneStatus zoneStatus(void) { return m_zoneStatus; }
    inline void setZoneStatus(ZoneStatus value) { m_zoneStatus = value; }

    inline bool descriptorReceived(void) { return m_descriptorReceived; }
    inline void setDescriptorReceived(void) { m_descriptorReceived = true; }

    inline bool updated(void) { return m_updated; }
    inline void setUpdated(bool value) { m_updated = value; }

    inline QList <Property> &properties(void) { return m_properties; }
    inline QList <Action> &actions(void) { return m_actions; }
    inline QList <Binding> &bindings(void) { return m_bindings; }
    inline QList <Reporting> &reportings(void) { return m_reportings; }
    inline QList <Poll> &polls(void) { return m_polls; }
    inline QList <Expose> &exposes(void) { return m_exposes; }

private:

    QTimer *m_timer;

    quint8 m_id;
    QWeakPointer <DeviceObject> m_device;

    quint32 m_pollInterval;
    qint64 m_pollTime;

    quint16 m_colorCapabilities, m_zoneType;
    ZoneStatus m_zoneStatus;

    bool m_descriptorReceived, m_updated;

    QList <Property> m_properties;
    QList <Action> m_actions;
    QList <Binding> m_bindings;
    QList <Reporting> m_reportings;
    QList <Poll> m_polls;
    QList <Expose> m_exposes;

};

class DeviceObject : public QObject
{
    Q_OBJECT

public:

    DeviceObject(const QByteArray &ieeeAddress, quint16 networkAddress, const QString name = QString(), bool removed = false) :
        QObject(nullptr), m_timer(new QTimer(this)), m_ieeeAddress(ieeeAddress), m_networkAddress(networkAddress), m_name(name), m_removed(removed), m_supported(false), m_descriptorReceived(false), m_endpointsReceived(false), m_interviewFinished(false), m_logicalType(LogicalType::EndDevice), m_manufacturerCode(0), m_powerSource(POWER_SOURCE_UNKNOWN), m_version(0), m_joinTime(0), m_lastSeen(0), m_linkQuality(0), m_availability(AvailabilityStatus::Unknown) {}

    inline QTimer *timer(void) { return m_timer; }
    inline QByteArray ieeeAddress(void) { return m_ieeeAddress; }

    inline quint16 networkAddress(void) { return m_networkAddress; }
    inline void setNetworkAddress(quint16 value) { m_networkAddress = value; }

    inline QString name(void) { return m_name.isEmpty() ? m_ieeeAddress.toHex(':') : m_name; }
    inline void setName(const QString &value) { m_name = value; }

    inline bool descriptorReceived(void) { return m_descriptorReceived; }
    inline void setDescriptorReceived(void) { m_descriptorReceived = true; }

    inline bool endpointsReceived(void) { return m_endpointsReceived; }
    inline void setEndpointsReceived(void) { m_endpointsReceived = true; }

    inline bool interviewFinished(void) { return m_interviewFinished; }
    inline void setInterviewFinished(void) { m_interviewFinished = true; }

    inline bool removed(void) { return m_removed; }
    inline void setRemoved(bool value) { m_removed = value; }

    inline bool supported(void) { return m_supported; }
    inline void setSupported(bool value) { m_supported = value; }

    inline quint8 interviewEndpointId(void) { return m_interviewEndpointId; }
    inline void setInterviewEndpointId(quint8 value) { m_interviewEndpointId = value; }

    inline quint8 lqiRequestIndex(void) { return m_lqiRequestIndex; }
    inline void setLqiRequestIndex(quint8 value) { m_lqiRequestIndex = value; }

    inline LogicalType logicalType(void) { return m_logicalType; }
    inline void setLogicalType(LogicalType value) { m_logicalType = value; }

    inline quint16 manufacturerCode(void) { return m_manufacturerCode; }
    inline void setManufacturerCode(quint16 value) { m_manufacturerCode = value; }

    inline bool batteryPowered(void) { return m_powerSource != POWER_SOURCE_MAINS && m_powerSource != POWER_SOURCE_DC; }
    inline quint8 powerSource(void) { return m_powerSource; }
    inline void setPowerSource(quint8 value) { m_powerSource = value; }

    inline quint8 version(void) { return m_version; }
    inline void setVersion(quint8 value) { m_version = value; }

    inline QString manufacturerName(void) { return m_manufacturerName; }
    inline void setManufacturerName(const QString &value) { m_manufacturerName = value; }

    inline QString modelName(void) { return m_modelName; }
    inline void setModelName(const QString &value) { m_modelName = value; }

    inline QString firmware(void) { return m_firmware; }
    inline void setFirmware(const QString &value) { m_firmware = value; }

    inline qint64 joinTime(void) { return m_joinTime; }
    inline void updateJoinTime(void) { m_joinTime = QDateTime::currentMSecsSinceEpoch(); }

    inline qint64 lastSeen(void) { return m_lastSeen; }
    inline void setLastSeen(qint64 value) { m_lastSeen = value; }
    inline void updateLastSeen(void) { m_lastSeen = QDateTime::currentSecsSinceEpoch(); }

    inline quint8 linkQuality(void) { return m_linkQuality; }
    inline void setLinkQuality(quint8 value) { m_linkQuality = value; }

    inline AvailabilityStatus availability(void) { return m_availability; }
    inline void setAvailability(AvailabilityStatus value) { m_availability = value; }

    inline QString description(void) { return m_description; }
    inline void setDescription(const QString &value) { m_description = value; }

    inline QMap <QString, QVariant> &options(void) { return m_options; }
    inline QMap <quint8, Endpoint> &endpoints(void) { return m_endpoints; }
    inline QMap <quint16, quint8> &neighbors(void) { return m_neighbors; }

private:

    QTimer *m_timer;

    QByteArray m_ieeeAddress;
    quint16 m_networkAddress;
    QString m_name;

    bool m_removed, m_supported, m_descriptorReceived, m_endpointsReceived, m_interviewFinished;
    quint8 m_interviewEndpointId, m_lqiRequestIndex;

    LogicalType m_logicalType;
    quint16 m_manufacturerCode;
    quint8 m_powerSource, m_version;
    QString m_manufacturerName, m_modelName, m_firmware;

    qint64 m_joinTime, m_lastSeen;
    quint8 m_linkQuality;

    AvailabilityStatus m_availability;
    QString m_description;

    QMap <QString, QVariant> m_options;
    QMap <quint8, Endpoint> m_endpoints;
    QMap <quint16, quint8> m_neighbors;

};

class DeviceList : public QObject, public QMap <QByteArray, Device>
{
    Q_OBJECT

public:

    DeviceList(QSettings *config, QObject *parent);
    ~DeviceList(void);

    inline bool names(void) { return m_names; }
    inline void setNames(bool value) { m_names = value; }

    inline bool permitJoin(void) { return m_permitJoin; }
    inline void setPermitJoin(bool value) { m_permitJoin = value; }

    void init(void);

    Device byName(const QString &name);
    Device byNetwork(quint16 networkAddress);
    Endpoint endpoint(const Device &device, quint8 endpointId);

    void identityHandler(const Device &device, QString &manufacturerName, QString &modelName);

    void setupDevice(const Device &device);
    void setupEndpoint(const Endpoint &endpoint, const QJsonObject &json, bool multiple = false);

    void recognizeDevice(const Device &device);
    void recognizeMultipleProperty(const Device &device, const Endpoint &endpoint, const Property &property);
    void recognizeMultipleExpose(const Device &device, const Endpoint &endpoint, const Expose &expose);

    void removeDevice(const Device &device);

    void storeDatabase(void);
    void storeProperties(void);

private:

    QTimer *m_databaseTimer, *m_propertiesTimer;

    QFile m_databaseFile, m_propertiesFile, m_optionsFile;
    QDir m_externalDir, m_libraryDir;
    bool m_offsets, m_names, m_permitJoin, m_sync;

    void unserializeDevices(const QJsonArray &devices);
    void unserializeProperties(const QJsonObject &properties);

    QJsonArray serializeDevices(void);
    QJsonObject serializeProperties(void);

    bool writeFile(QFile &file, const QByteArray &data, bool sync = false);

private slots:

    void writeDatabase(void);
    void writeProperties(void);
    void endpointTimeout(void);

signals:

    void statusUpdated(const QJsonObject &json);
    void endpointUpdated(const Device &device, quint8 endpointId);
    void pollRequest(EndpointObject *endpoint, const Poll &poll);

};

#endif
